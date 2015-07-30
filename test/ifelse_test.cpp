//
// ... Standard header files
//

#include <iostream>



//
// ... Lisp header files
//
#include <lisp/nil.hpp>
#include <lisp/ifelse.hpp>
#include <lisp/expr.hpp>
#include <lisp/builtin.hpp>

using Lisp::nil;
using Lisp::eval;
using Lisp::add;
using Lisp::ifelse;



int
main( int argc, char** argv )
{

  constexpr auto a = 1;
  constexpr auto b = 2;
  constexpr auto c = 3;


  constexpr auto x = ifelse( true, 1, 2 );

  constexpr auto y = ifelse( nil, 1, 2 );


  
  return 0;
}
