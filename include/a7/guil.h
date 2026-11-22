#ifndef A7_GUIL_H
#define A7_GUIL_H

#ifdef __cplusplus
extern "C" {
#endif

struct A7GuilContext;
typedef struct A7GuilContext *A7GuilContextPtr;
/*
 * negative(`<0`): hard error, clean pointer to `NULL`
 * positive(`>0`): soft error (warning)
 */
enum A7GuilError {
    A7GuilError_Hard_Active = -1,
    A7GuilError_Hard_InitSDL = -2,
    A7GuilError_Hard_WindowSDL = -3,
    A7GuilError_Hard_Pipe = -4,
    A7GuilError_Hard_Fork = -5,
    A7GuilError_None = 0,
    A7GuilError_Soft_TODO = 1
};

struct A7Guil {
    A7GuilContextPtr value;
    enum A7GuilError error;
};

/* TODO: add create with configuration, where `config` passed as
 * a first out parameter, so passed hints could be overwritten
 * to what actually was applied, with after input parameter
 * like enum strict mode which would return NULL if hints cannot be applied */
struct A7Guil a7_guil_create( void );

A7GuilContextPtr a7_guil_delete( A7GuilContextPtr value );

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE GUARD */

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
