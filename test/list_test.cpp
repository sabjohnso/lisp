//
// ... Lisp header files
//
#include <lisp/list.hpp>



int
main( int argc, char** argv )
{

  using Lisp::nil;
  using Lisp::null;
  using Lisp::not_null;
  using Lisp::list;
  using Lisp::listp;

  // listp should return nil for arguments that are not lists.
  {
    COMBINE_STATIC_ASSERT_TRUE( null( listp( 1 )));
  }

  // Build a list at compile time from rvalues.
  {
    constexpr auto x = list( 1, 2, 3, 4 );
    COMBINE_STATIC_ASSERT_TRUE( not_null( listp( x )));
    COMBINE_STATIC_ASSERT_EQUAL( 1, x.first );
    COMBINE_STATIC_ASSERT_EQUAL( 2, x.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( 3, x.second.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( 4, x.second.second.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( nil, x.second.second.second.second );
  }

  // Build a list at compile time from lvalues
  {
    constexpr auto a = 1;
    constexpr auto b = 2;
    constexpr auto c = 3;
    constexpr auto d = 4;
    constexpr auto x = list( a, b, c, d );
    COMBINE_STATIC_ASSERT_TRUE( not_null( listp( x )));
    COMBINE_STATIC_ASSERT_EQUAL( 1, x.first );
    COMBINE_STATIC_ASSERT_EQUAL( 2, x.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( 3, x.second.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( 4, x.second.second.second.first );
    COMBINE_STATIC_ASSERT_EQUAL( nil, x.second.second.second.second );
  }

  // Build a list at run time.
  {
    auto a = 1;
    auto b = 2;
    auto c = 3;
    auto d = 4;
    auto x = list( a, b, c, d );

    if( null( listp( x )))
    {
      throw( std::logic_error( "The function listp returned an incorrect value at runtime." ));
    }
    if( a != x.first )
    {
      throw( std::logic_error( "The function list returned an incorrect value at runtime (1)." ));
    }
    if( b != x.second.first )
    {
      throw( std::logic_error( "The function list returned an incorrect value at runtime (2)." ));
    }
    if( c != x.second.second.first )
    {
      throw( std::logic_error( "The function list returned an incorrect value at runtime (3)." ));
    }
    if( d != x.second.second.second.first )
    {
      throw( std::logic_error( "The function list returned an incorrect value at runtime (4)." ));
    }
    if( nil != x.second.second.second.second )
    {
      throw( std::logic_error( "The function list returned an incorrect value at runtime (nil)." ));
    }    
  }
  

  return 0;
  
};
