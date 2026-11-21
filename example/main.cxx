#include <a7/guil.h>
// `son8`
#include <son8/windowed.hxx>
#include <glad/son8.hxx>
// `std`
#include <cassert>

namespace wnd = son8::windowed;

int main( ) {
    auto guil = a7_guil_create( );
    assert( guil != NULL and "guil null on creation" );

    wnd::Window window;

    window.run( []{
        glClearColor( 0.8, 0.1, 0.1, 0.0 );
        glClear( GL_COLOR_BUFFER_BIT );
    });

    guil = a7_guil_delete( );
    assert( guil == NULL and "guil not null on deletion" );
}
