
//
// ... Standard header files
//
#include <stdexcept>


//
// ... Lisp header files
//
#include <lisp/cons.hpp>


using Lisp::cons;
using Lisp::consp;
using Lisp::null;
using Lisp::not_null;
using Lisp::car;
using Lisp::cdr;

int
main( int argc, char** argv )
{

  // consp should return nil with argumens that are not pairs
  {
    COMBINE_STATIC_ASSERT_TRUE( null( consp( 1 )));
  }
  
  // Construct the pair from rvalues
  {
    constexpr auto x = cons( 1, 2 );
    COMBINE_STATIC_ASSERT_EQUAL( x.first,  1 );
    COMBINE_STATIC_ASSERT_EQUAL( x.second, 2 );
    COMBINE_STATIC_ASSERT_TRUE( not_null( consp( x )));
  }

  // Construct the pair from lvalues
  {
    constexpr auto a = 1;
    constexpr auto b = 'x';
    constexpr auto ab = cons( a, b );
    COMBINE_STATIC_ASSERT_EQUAL( a, ab.first );
    COMBINE_STATIC_ASSERT_EQUAL( b, ab.second );
    COMBINE_STATIC_ASSERT_TRUE( not_null( consp( ab )));
    COMBINE_STATIC_ASSERT_EQUAL( a, car( ab ));
    COMBINE_STATIC_ASSERT_EQUAL( b, cdr( ab ));
    
  }

  // Construct the pair from lvalues at runtime
  {
    auto a = 1;
    auto b = 'x';
    auto ab = cons( a, b );

    if( ab.first != a )
    {
      throw( std::logic_error( "The function cons returned an incorrect car value at runtime." ));
    }
    if( ab.second != b )
    {
      throw( std::logic_error( "The function cons returned an incorrect cdr value at runtime." ));
    }
    if( null( consp( ab )))
    {
      throw( std::logic_error( "The function `consp' return an incorrect response at runtime." ));
    }
  }

  return 0;
}
