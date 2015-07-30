/**

   @file
   symbol.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/
#ifndef SYMBOL_HPP_INCLUDED_1008820247957931861
#define SYMBOL_HPP_INCLUDED_1008820247957931861

//
// ... Lisp header files
//
#include <lisp/nil.hpp>
#include <lisp/import.hpp>


namespace Lisp
{


  template< size_t index >
  struct Symbol{};

  template< typename ... >
  struct Symbolp
  {
    constexpr static bool value = false;
  };

  template< typename X >
  struct Symbolp< X >
  {
    template< typename ... >
    struct Aux
    {
      constexpr static bool value = false;
    };

    template< size_t index >
    struct Aux< Symbol<index> >
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
    operator()( X&& x )
    {
      return aux( Datum< bool, Symbolp<X>::value >{}, x );
    }

  private:

    template< typename X >
    constexpr auto
    aux( True, X&& x )
    {
      return move( x );
    }

    template< typename X >
    constexpr auto
    aux( False, X&& )
    {
      return nil;
    }
    
  } symbolp{};

  
} // end of namespace Lisp


#endif // SYMBOL_HPP_INCLUDED_1008820247957931861
