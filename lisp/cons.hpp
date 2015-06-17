/**
   @file
   cons.hpp

   @brief
   Construct a pair.

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>
*/


#ifndef CONS_HPP_INCLUDED_1777129736546437720
#define CONS_HPP_INCLUDED_1777129736546437720


//
// ... Lisp header files
//
#include <lisp/import.hpp>
#include <lisp/nil.hpp>

namespace Lisp
{

  constexpr static auto cons = MakeXs< pair >{};

  template< typename ... >
  struct Pairp
  {
    constexpr static bool value = false;
  };

  template< typename X >
  struct Pairp< X >
  {
    template< typename ... >
    struct Aux
    {
      constexpr static bool value = false;
    };

    template< typename A, typename B >
    struct Aux< pair<A,B> >
    {
      constexpr static bool value = true;
    };

    constexpr static bool value = Aux< typename decay<X>::type >::value;
    
  };

  constexpr static
  struct
  {
    template< typename X >
    constexpr auto
    operator ()( X&& x ) const
    {
      return aux( Datum< bool, Pairp<X>::value >{}, forward<X>( x ));
    }

    template< typename X >
    constexpr auto
    operator ()( const X& x ) const
    {
      return aux( Datum< bool, Pairp<X>::value >{}, x );
    }

    template< typename ... Xs >
    constexpr auto
    operator ()( Xs ... ) const
    {
      return nil;
    }

  private:

    
    template< typename X >
    constexpr auto
    aux( True, X&& x ) const
    {
      return std::move( x );
    }

    template< typename X >
    constexpr auto
    aux( True, const X& x ) const
    {
      return x;
    }

    template< typename X >
    constexpr auto
    aux( False, X ) const
    {
      return nil;
    }
    
  } consp{};


  struct
  {

    template< typename A, typename B >
    constexpr auto
    operator()( const pair<A,B>& x )
    {
      return x.first;
    }

    template< typename A, typename B >
    constexpr auto
    operator()( pair<A,B>&& x )
    {
      return move( x.first );
    }

    template< typename ... Xs >
    constexpr auto
    operator ()( const Xs& ... xs )
    {
      return nil;
    }
    
  } car{};

  
  struct
  {
    template< typename A, typename B >
    constexpr auto
    operator()( const pair<A,B>& x )
    {
      return x.second;
    }

    template< typename A, typename B >
    constexpr auto
    operator()( pair<A,B>&& x )
    {
      return move( x.second );
    }

    template< typename ... Xs >
    constexpr auto
    operator()( const Xs& ... xs )
    {
      return nil;
    }

    
  } cdr{};
  
  

} //  end of namemspace Lisp


#endif // CONS_HPP_INCLUDED_1777129736546437720
