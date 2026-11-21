#ifndef A7_GUIL_H
#define A7_GUIL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct A7Guil_ A7Guil;
typedef struct A7Guil_ *A7GuilPtr;

A7GuilPtr a7_guil_create( );
/* NOTE: always returns NULL just to clear original if needed */
A7GuilPtr a7_guil_delete( );


#ifdef __cplusplus
}
#endif

#endif /* INCLUDE GUARD */

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
