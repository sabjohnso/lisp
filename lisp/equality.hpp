/**
   @file
   equality.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohsno@yahoo.com>
*/


#ifndef EQUALITY_HPP_INCLUDED
#define EQUALITY_HPP_INCLUDED


//
// ... Lisp header files
//
#include <lisp/nil.hpp>



namespace Lisp
{

  /** Return true if two objects are the same object, false otherwise. */
  constexpr static
  struct Eq
  {
    template< typename X, typename Y >
    constexpr static
    operator()( const X& x, const Y& y ) const
    {
      return false;
    }

    template< typename X >
    constexpr static
    operator ()( const X& x0, const X& x1 )
    {
      return (&x0) == (&x1);
    }

  } eq{};

  /** Return non-nil if arguments are eq or if they are values of fundamental 
      types with the same type and value. */
  constexpr static
  struct Eql
  {
    template< typename X, typename Y >
    constexpr static
    operator()( const X& x, const Y& y ) const
    {
      return false;
    }

    template< typename X >
    constexpr static
    operator ()( const X& x0, const X& x1 ) const
    {
      return x0 == x1;
    }

    
  } eql{};

  /** Return non-nil if two objects are structurally the same. */
  constexpr static
  struct Equal
  {
  } equal{};

  /** Return true if the object are structurally similar, and components 
      are numerically the equal regardless of their types.
  */
  constexpr static
  struct Equalp
  {
  }equalp{};
  
} // end of namespace Lisp


#endif // EQUALITY_HPP_INCLUDED
