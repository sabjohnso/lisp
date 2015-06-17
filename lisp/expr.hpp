/**
   @file
   expr.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/
#ifndef EXPR_HPP_INCLUDED_1444652657799346692
#define EXPR_HPP_INCLUDED_1444652657799346692


//
// ... Lisp header files
//
#include <lisp/import.hpp>
#include <lisp/cons.hpp>
#include <lisp/list.hpp>

namespace Lisp
{

  template< typename ... >
  struct Exprp
  {
    constexpr static bool value = false;
  };

  template< typename F, typename Xs >
  struct Exprp< pair<F,Xs> >
  {
    template< typename ... >
    struct Aux
    {
      constexpr static bool value = false;
    };

    template< typename G, typename ... Ys >
    struct Aux< True, G, Types< Ys ... > >
    {
      constexpr static bool value = is_function<G(Ys...)>::value;
    };

    constexpr static bool value = Aux< Datum< bool, Listp< Xs >::value >, F, typename List_types< Xs >::type >::value;
    
  };

  constexpr static
  struct
  {
    
    template< typename ... Xs >
    constexpr auto
    operator ()( const Xs& ... xs )
    {
      return aux( Datum< bool, Exprp< Xs ... >::value >{}, xs ... );
    }

  private:
    
    template< typename X >
    constexpr auto
    aux( True, const X& x )
    {
      return x;
    }

    template< typename X >
    constexpr auto
    aux( False, const X& )
    {
      return nil;
    }
    
  } expr_p{};


  constexpr static
  struct
  {
    template< typename X >
    constexpr auto
    operator ()( const X& x ) const
    {
      return aux0( Datum< bool, Exprp<X>::value >{}, x );
    }

    template< typename X >
    constexpr auto
    operator ()( X&& x ) const
    {
      return aux0( Datum< bool, Exprp<X>::value >{}, forward<X>( x ));
    }

  private:

    template< typename X >
    constexpr auto
    aux0( False, X const& x ) const
    {
      return x;
    }

    template< typename X >
    constexpr auto
    aux0( False, X&& x ) const
    {
      return move( x );
    }

    template< typename X >
    constexpr auto
    aux0( True, X const& x ) const
    {
      return aux1( car( x ), cdr( x ));
    }

    template< typename X >
    constexpr auto
    aux0( True, X&& x ) const
    {
      return aux1( car( forward<X>( x )), cdr( forward<X>( x )));
    }

    template< typename F, typename ... Xs >
    constexpr auto
    aux1( F&& f, Nil&&, Xs&& ... xs )
    {
      return f( aux0( Datum< bool, Exprp<Xs>::value >{}, forward<Xs>( xs )) ... );
    }
    
    template< typename F, typename X, typename ... Xs >
    constexpr auto
    aux1( F&& f, X&& x, Xs&& ... xs )
    {
      return aux1( forward<F>( f ), cdr( forward<X>( x )), forward<Xs>( xs ) ..., car( forward<X>( x )));
    }

  } eval{};

  
  
} // end of namespace Lisp


#endif // ! defined EXPR_HPP_INCLUDED_1444652657799346692
