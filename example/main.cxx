#include <a7/guil.h>
// `son8`
#include <son8/windowed.hxx>
#include <glad/son8.hxx>
// `std`
#include <cassert>
#include <cstddef>

namespace wnd = son8::windowed;

int main( ) {
    auto guil = a7_guil_create( );
    assert( guil != NULL and "guil null on creation" );

    wnd::Config config;
    config.set( wnd::OpenGL::Vx0303CB );
    config.set( wnd::Config::Width{ 1280u });
    config.set( wnd::Config::Height{ 720u });
    wnd::Window{ config }.run( []{
        glClearColor( .2, .3, .3, .0 );
        glClear( GL_COLOR_BUFFER_BIT );
    });

    guil = a7_guil_delete( );
    assert( guil == NULL and "guil not null on deletion" );
}

// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `guil` C90 Detached Process GUI Library
// Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
