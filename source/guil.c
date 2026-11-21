#include <a7/guil.h>
/* stdc90 */
#include <stddef.h>

/* private implementation */

struct A7Guil_ {

};

/* public interface */

A7GuilPtr a7_guil_create( ) {
    static struct A7Guil_ guil;
    return &guil;
}

A7GuilPtr a7_guil_delete( ) {
    return NULL;
}

/* Apache License 2.0
 * NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
 * SPDX-License-Identifier: Apache-2.0
 * lib: `guil` C90 Detached Process GUI Library
 * Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
