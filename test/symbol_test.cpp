//
// ... Lisp header files
//
#include <lisp/symbol.hpp>


using Lisp::Symbol;
using Lisp::symbolp;
using Lisp::not_null;
using Lisp::null;


int
main( int argc, char** argv )
{
  constexpr static
  struct Y
  {} y{};
  constexpr static auto x = Symbol<0>{};

  COMBINE_STATIC_ASSERT_TRUE( not_null( symbolp( x )));
  COMBINE_STATIC_ASSERT_TRUE( null( symbolp( y )));
  
  return 0;
}
