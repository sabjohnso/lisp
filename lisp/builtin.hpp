/**
   @file
   builtin.hpp

   @brief
   UNDOCUMENTED

   @copyright	
   2015 Samuel B. Johnson

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com

*/


#ifndef BUILTIN_HPP_INCLUDED_1765873302180636196
#define BUILTIN_HPP_INCLUDED_1765873302180636196

namespace Lisp
{

  constexpr static auto add = Addition{};
  constexpr static auto sub = Subtraction{};
  constexpr static auto mul = Multiplication{};
  constexpr static auto div = Division{};
  constexpr static auto mod = Modulo{};
  
} // Builtin


#endif // BUILTIN_HPP_INCLUDED_1765873302180636196
