/**
   @file
   quote.hpp

   @brief
   UNDOCUMENTED

   @copyright	
   2015 Samuel B. Johnson

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef QUOTE_HPP_INCLUDED_278243166798699397
#define QUOTE_HPP_INCLUDED_278243166798699397 1

namespace Lisp
{

  /** Quasi-quotation
   */
  struct Quasi_quote
  {};

  /** Quote
   */
  struct Quote
  {
    template< typename X>
    constexpr auto
    operator ()( X&& x )
    {
      return move( x );
    }
  } quote;

  

  
  /** Escape from quasi-quotation.
   */
  constexpr static
  struct
  {
  } unquote{};
  


  
} // end of namespace Lisp

#endif // ! defined QUOTE_HPP_INCLUDED_278243166798699397
