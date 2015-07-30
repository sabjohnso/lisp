/**

   @file
   ifelse.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef IFELSE_HPP_INCLUDED_1861027821860851001
#define IFELSE_HPP_INCLUDED_1861027821860851001

//
// ... Lisp header files
//
#include <lisp/nil.hpp>
#include <lisp/expr.hpp>

namespace Lisp
{

  constexpr static 
  struct
  {
    template< typename Test, typename Pass, typename Fail >
    constexpr auto
    operator ()( Test, Pass&& pass, Fail&& ) const
    {
      return pass;
    }

    template< typename Pass, typename Fail >
    constexpr auto
    operator ()( Nil, Pass&&, Fail&& fail ) const
    {
      return fail;
    }
  } ifelse{};
    
  
} // end of namespace Lisp


#endif // IFELSE_HPP_INCLUDED_1861027821860851001
