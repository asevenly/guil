#define _POSIX_C_SOURCE 200809L
/* `a7` */
#include <a7/guil.h>
/* `stdc90` */
#include <assert.h>
#include <errno.h>
#include <stddef.h>
/* `posix` */
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/* `sdl2` */
#include <SDL.h>

/* private implementation */

#define A7_GUIL_INIT_IN( name )\
    struct A7GuilContext const *name = &A7_Guil_Context
#define A7_GUIL_INIT_OUT( name )\
    struct A7GuilContext *name##Out = &A7_Guil_Context
#define A7_GUIL_INIT( name )\
    A7_GUIL_INIT_IN( name );\
    A7_GUIL_INIT_OUT( name )


struct A7GuilContext {
    struct {
        unsigned int active : 1;
    } flags;
    struct {
        pid_t childPID;
    } linOS;
};

static struct A7GuilContext A7_Guil_Context = {
    { 0 }, /* flags */
    { 0 }  /* linOS */
};

static struct A7Guil error_None( A7GuilContextPtr value ) {
    /* init */
    struct A7Guil init = { 0 };
    /* body */
    assert( value != NULL );
    init.value = value;

    return init;
}

static struct A7Guil error_Hard( enum A7GuilError error ) {
    /* init */
    struct A7Guil init = { 0 };
    /* body */
    assert( error < 0 );
    init.error = error;

    return init;
}

static struct A7Guil error_Soft( A7GuilContextPtr value, enum A7GuilError warn ) {
    /* init */
    struct A7Guil init;
    /* body */
    assert( value != NULL );
    assert( warn > 0 );
    init.value = value;
    init.error = warn;

    return init;
}

typedef SDL_Window *WindowPtr;
typedef SDL_Surface *SurfacePtr;

struct DataSDL {
    WindowPtr windowPtr;
    SurfacePtr surfacePtr;
};
typedef struct DataSDL *DataSDLPtr;

static void refresh_Surface_SDL( struct DataSDL sdl ) {
    if ( sdl.surfacePtr ) {
        SDL_FillRect( sdl.surfacePtr, NULL, SDL_MapRGB( sdl.surfacePtr->format, 80, 32, 38 ));
        SDL_UpdateWindowSurface( sdl.windowPtr );
    }
}

static enum A7GuilError init_SDL( DataSDLPtr sdlPtr ) {
    int centered = SDL_WINDOWPOS_CENTERED;
    /* NOTE: init zero is good! */
    if ( SDL_Init( SDL_INIT_VIDEO )) { return A7GuilError_Hard_InitSDL; }

    sdlPtr->windowPtr = SDL_CreateWindow( "A7 Guil", centered, centered, 640, 360, SDL_WINDOW_RESIZABLE );

    if ( !sdlPtr->windowPtr ) {
        SDL_Quit( );
        return A7GuilError_Hard_WindowSDL;
    }

    sdlPtr->surfacePtr = SDL_GetWindowSurface( sdlPtr->windowPtr );
    refresh_Surface_SDL( *sdlPtr );

    return A7GuilError_None;
}

static void run_SDL( struct DataSDL sdl ) {

    int isClosing = 0;

    while ( !isClosing ) {
        SDL_Event ev;
        while ( SDL_PollEvent( &ev )) {
            if ( ev.type == SDL_QUIT ) { isClosing = 1; };
        }
        SDL_Delay( 20 );
    }

    SDL_DestroyWindow( sdl.windowPtr );
    SDL_Quit( );
}

/* public interface */

struct A7Guil a7_guil_create( void ) {
    /* init */
    A7_GUIL_INIT( guil );
    /* body */
    if ( guil->flags.active ) { return error_Hard( A7GuilError_Hard_Active ); }

    {
        /* linOS specific */
        /* TODO: make separate function */
        pid_t forkPID = fork( );

        if ( forkPID < 0 ) { return error_Hard( A7GuilError_Hard_Fork ); }

        if ( forkPID == 0 ) {
            /* NOTE: this is already separate process
             * \ that's why not error returns here */
            struct DataSDL sdl = { 0 };

            if ( init_SDL( &sdl ) == A7GuilError_None ) {
                run_SDL( sdl );
            }

            _exit( 0 );
        }

        guilOut->linOS.childPID = forkPID;
    }

    guilOut->flags.active = 1;

    return error_None( guilOut );
}

A7GuilContextPtr a7_guil_delete( A7GuilContextPtr value ) {
    if ( !value || !value->flags.active ) { return NULL; }

    {
        /* linOS specific */
        /* TODO: make separate function */
        kill( value->linOS.childPID, SIGTERM );
        waitpid( value->linOS.childPID, NULL, 0 );
        value->linOS.childPID = 0;
    }

    value->flags.active = 0;
    return NULL;
}

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
