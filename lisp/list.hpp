/**

   @file
   list.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/
#ifndef LIST_HPP_INCLUDED_1448365634502885537
#define LIST_HPP_INCLUDED_1448365634502885537 1


//
// ... Lisp header files
//
#include <lisp/nil.hpp>
#include <lisp/import.hpp>
#include <lisp/cons.hpp>



namespace Lisp
{

  constexpr static
  struct
  {
    template< typename ... Xs >
    constexpr auto
    operator()( Xs&& ... xs ) const
    {
      return  aux( forward<Xs>( xs ) ... );
    }

    template< typename ... Xs >
    constexpr auto
    operator()( const Xs& ... xs ) const
    {
      return  aux( xs ... );
    }

  private:

    constexpr auto
    aux()
    {
      return nil;
    }

    template< typename X, typename ... Xs >
    constexpr auto
    aux( X&& x,  Xs&& ... xs  ) const
    {
      return cons( forward<X>( x ), aux( forward<Xs>( xs ) ... ));
    }

    
    template< typename X, typename ... Xs >
    constexpr auto
    aux( const X& x,  const Xs& ... xs  ) const
    {
      return cons( x, aux( xs ... ));
    }
    
  } list{};


  template< typename ... >
  struct Listp
  {
    constexpr static bool value = false;
  };

  template< typename X >
  struct Listp<X>
  {
    template< typename ... >
    struct Aux
    {
      constexpr static bool value = false;
    };

    template< typename ... Xs >
    struct Aux< Nil, Xs ... >
    {
      static_assert( count_types<Xs ... >() == 0, "This is an invalid call." );
      constexpr static bool value = true;
    };

    template< typename A, typename B >
    struct Aux< pair<A,B> >
    {
      constexpr static bool value = Aux< typename decay<B>::type >::value;
    };


    constexpr static bool value = Aux< typename decay<X>::type >::value;
  };


  template< typename ... >
  struct List_types
  {
    using type =  Nil;
  };

  template< typename X >
  struct List_types< X >
  {
    template< typename ... >
    struct Aux
    {
      using type = Nil;
    };

    template< typename ... Xs >
    struct Aux< True, Nil, Xs ... >
    {
      using type = Types< Xs ... >;
    };

    template< typename A, typename B, typename ... Xs >
    struct Aux< True, pair<A,B>, Xs ... > : Aux< True, typename decay<B>::type, Xs ..., typename decay<A>::type >
    {};
      
    using type = typename Aux< Datum< bool, Listp<X>::value >, typename decay<X>::type >::type;
  };


  constexpr static
  struct
  {
    template< typename ... Xs >
    constexpr auto
    operator()( Xs&& ... xs )
    {
      return aux( Datum< bool, Listp< Xs ... >::value >{},
		  forward<Xs>( xs ) ... );
    }

  private:

    template< typename ... Xs >
    constexpr auto
    aux( False, Xs ... )
    {
      return nil;
    }

    template< typename X >
    constexpr auto
    aux( True, X&& x )
    {
      return move( x );
    }

    template< typename X >
    constexpr auto
    aux( True, const X& x )
    {
      return x;
    }
		
  } listp{};


  constexpr static
  struct
  {
    template< typename A, typename B >
    constexpr auto
    reverse( pair<A,B>&& xs )
    {
      static_assert( listp( xs ), "Argument for reverse is not a list." );
      return aux( forward< pair<A,B> >( xs ), Nil{} );
    }

    template< typename A, typename B >
    constexpr auto
    reverse( const pair<A,B>&& xs )
    {
      static_assert( listp( xs ), "Argument for reverse is not a list." );
      return aux( xs, Nil{} );
    }

  private:

    
    template< typename Accum >
    constexpr auto
    aux( Accum&& accum, Nil )
    {
      return move( accum );
    }
    
    template< typename A, typename B,  typename Accum >
    constexpr auto
    aux( pair<A,B>&& xs, Accum&& accum )
    {
      return aux( cdr( forward<pair<A,B>>( xs )), cons( forward<pair<A,B>>( xs ), forward<Accum>( accum )));
    }
    
  } reverse{};
  

  
  
} // end of namespace Lisp

#endif // ! defined LIST_HPP_INCLUDED_1448365634502885537
