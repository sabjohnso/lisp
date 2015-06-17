/**
   @file
   nil.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>
*/

#ifndef NIL_HPP_INCLUDED
#define NIL_HPP_INCLUDED

//
// ... Lisp header files
//
#include <lisp/import.hpp>


namespace Lisp
{

  struct Nil{};

  constexpr auto
  operator==( const Nil&, const Nil& )
  {
    return true;
  }

  template< typename X >
  constexpr auto
  operator==( const X&, const Nil& )
  {
    return false;
  }

  template< typename X >
  constexpr auto
  operator==( const Nil& , const X& )
  {
    return false;
  }

  template< typename X >
  constexpr auto
  operator !=( const Nil& nil, const X& x )
  {
    return !( nil == x );
  }

  template< typename X >
  constexpr auto
  operator !=( const X& x, const Nil& nil )
  {
    return !( nil == x );
  }

  constexpr auto
  operator !=( const Nil& nil0, const Nil& nil1 )
  {
    return !( nil0 == nil1 );
  }

  constexpr static auto nil = Nil{};


  template< typename ... >
  struct Null
  {
    constexpr static bool value = false;
  };

  template<>
  struct Null< Nil >
  {
    constexpr static bool value = true;
  };


  constexpr static 
  struct
  {
    template< typename ... Xs >
    constexpr auto 
    operator()( Xs ... ) const
    {
      return Null< typename decay<Xs >::type ... >::value;
    }
  } null{};

  constexpr static
  struct
  {
    template< typename ... Xs >
    constexpr auto
    operator()( Xs ... ) const
    {
      return ! Null< typename decay<Xs>::type ... >::value;
    }
  } not_null{};
    

    

} // end of namespace Lisp


#endif // NIL_HPP_INCLUDED
