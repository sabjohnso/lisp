/**
   @file
   builtin.hpp

   @brief
   UNDOCUMENTED

   @copyright	
   2015 Halliburton Energy Services, Inc.

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>

 This is a CONFIDENTIAL document.
Neither the whole or any part of this document may
be reproduced, stored in any retrieval system or
transmitted in any form or by any means (electronic,
mechanical, reprographic, recording or otherwise)
without the prior consent of the copyright owner.
*/


#ifndef BUILTIN_HPP_INCLUDED_1765873302180636196
#define BUILTIN_HPP_INCLUDED_1765873302180636196

namespace Lisp
{

  constexpr static auto add = Addition{};
  constexpr static auto sub = Subtraction{};
  constexpr static auto mul = Multiplication{};
  constexpr static auto div = Division{};
  constexpr static auto mod = Modulous{};
  
} // Builtin


#endif // BUILTIN_HPP_INCLUDED_1765873302180636196
