#include <a7/guil.h>
/* stdc90 */
#include <assert.h>
#include <stddef.h>

/* private implementation */

#define A7_GUIL_INIT_IN( name )\
    struct A7GuilContext const *name = &A7_Guil_Context
#define A7_GUIL_INIT_OUT( name )\
    struct A7GuilContext *name##Out = &A7_Guil_Context
#define A7_GUIL_INIT( name )\
    A7_GUIL_INIT_IN( name );\
    A7_GUIL_INIT_OUT( name )

struct A7GuilContextFlags {
    unsigned int active : 1;
};

struct A7GuilContext {
    struct A7GuilContextFlags flags;
};

static struct A7GuilContext A7_Guil_Context = { 0 };

static struct A7Guil a7_Guil_Ret_Value( A7GuilContextPtr value ) {
    /* init */
    struct A7Guil init = { 0 };
    /* body */
    assert( value != NULL );
    init.value = value;

    return init;
}

static struct A7Guil a7_Guil_Ret_Error( enum A7GuilError error ) {
    /* init */
    struct A7Guil init = { 0 };
    /* body */
    assert( error < 0 );
    init.error = error;

    return init;
}

static struct A7Guil a7_Guil_Ret_Warn( A7GuilContextPtr value, enum A7GuilError warn ) {
    /* init */
    struct A7Guil init;
    /* body */
    assert( value != NULL );
    assert( warn > 0 );
    init.value = value;
    init.error = warn;

    return init;
}

/* public interface */

struct A7Guil a7_guil_create( void ) {
    /* init */
    A7_GUIL_INIT( guil );
    /* body */
    if ( guil->flags.active ) { return a7_Guil_Ret_Error( A7GuilError_Hard_AlreadyActive ); }

    guilOut->flags.active = 1;

    return a7_Guil_Ret_Value( guilOut );
}

A7GuilContextPtr a7_guil_delete( A7GuilContextPtr value ) {
    if ( !value || !value->flags.active ) { return NULL; }

    value->flags.active = 0;
    return NULL;
}

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
