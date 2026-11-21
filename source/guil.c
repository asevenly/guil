#include <a7/guil.h>
/* stdc90 */
#include <assert.h>
#include <stddef.h>

/* private implementation */

#define A7_GUIL_INIT_IN( name )\
    struct A7GuilContext_ const *name = &A7_Guil_Context
#define A7_GUIL_INIT_OUT( name )\
    struct A7GuilContext_ *name##Out = &A7_Guil_Context
#define A7_GUIL_INIT( name )\
    A7_GUIL_INIT_IN( name );\
    A7_GUIL_INIT_OUT( name )

struct A7GuilContext_ {
    unsigned int activeBit_ : 1;
};

static struct A7GuilContext_ A7_Guil_Context = { 0 };

static struct A7Guil a7_Guil_Ret_Value( A7GuilContextPtr value ) {
    struct A7Guil init = { 0 };
    assert( value != NULL );
    init.value = value;

    return init;
}

static struct A7Guil a7_Guil_Ret_Error( int error ) {
    struct A7Guil init = { 0 };
    assert( error > 0 );
    init.error = error;

    return init;
}

static struct A7Guil a7_Gui_Ret_Warn( A7GuilContextPtr value, int warn ) {
    struct A7Guil init;
    assert( value != NULL );
    assert( warn < 0 );
    init.value = value;
    init.error = warn;

    return init;
}

/* public interface */

struct A7Guil a7_guil_create( void ) {
    /* init */
    A7_GUIL_INIT( guil );
    /* body */
    if ( guil->activeBit_ ) { return a7_Guil_Ret_Error( A7GuilError_Hard_AlreadyActive ); }

    guilOut->activeBit_ = 1;

    return a7_Guil_Ret_Value( guilOut );
}

A7GuilContextPtr a7_guil_delete( A7GuilContextPtr value ) {
    if ( !value || !value->activeBit_ ) { return NULL; }

    value->activeBit_ = 0;
    return NULL;
}

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
