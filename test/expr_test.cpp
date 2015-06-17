
//
// ... Lisp header files
//
#include <lisp/import.hpp>
#include <lisp/expr.hpp>
#include <lisp/builtin.hpp>


int
main( int argc, char** argv )
{
  using Lisp::not_null;
  using Lisp::null;
  using Lisp::add;
  using Lisp::mul;
  using Lisp::list;
  using Lisp::expr_p;
  using Lisp::eval;
  using Lisp::car;
  using Lisp::cdr;

  
  {
    constexpr auto ex = list( add, 1, 2 );
    constexpr auto x = eval( ex );
    COMBINE_STATIC_ASSERT_TRUE( not_null( expr_p( ex )));
    COMBINE_STATIC_ASSERT_TRUE( null( expr_p( 1 )));
    COMBINE_STATIC_ASSERT_EQUAL( 1, car( cdr( ex )));
    COMBINE_STATIC_ASSERT_EQUAL( 2, car( cdr( cdr( ex ))));
    COMBINE_STATIC_ASSERT_EQUAL( 3, car( ex )( car( cdr( ex )), car( cdr( cdr( ex )))));
    COMBINE_STATIC_ASSERT_EQUAL( 3, eval( ex ));
  }
  
  {
    constexpr auto ex = list( mul, 1, 2, 3 );
    constexpr auto x = eval( ex );
    COMBINE_STATIC_ASSERT_EQUAL( 6, x );
  }

  {
    constexpr auto ex = list( mul, 1, 2, list( add, 1, 2 ));
    constexpr auto x = eval( ex );
    COMBINE_STATIC_ASSERT_EQUAL( 6, x );
  }

  {
    constexpr auto a = 1;
    constexpr auto b = 2;
    COMBINE_STATIC_ASSERT_EQUAL( 6, eval( list( mul, 1, 2, list( add, 1, 2 ))));
  }


  
  return 0;
}
