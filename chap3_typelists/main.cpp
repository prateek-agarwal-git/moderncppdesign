#include <iostream>

#include "include/appending_typelists.h"
#include "include/index_of.h"
#include "include/length_type_list.h"
#include "include/type_at.h"
#include "include/type_list_macros.h"
#include <cassert>
#include <string>

using type_3 = TYPELIST_3(int, double, char);
using type_4 = TYPELIST_4(int, double, char, long long);
int main() {
  std::cout << TL::Length<TYPELIST_1(int)>::value << std::endl;
  std::cout << TL::Length<TYPELIST_2(int, double)>::value << std::endl;
  std::cout << TL::Length<type_3>::value << std::endl;
  std::cout << TL::Length<type_4>::value << std::endl;

  assert(sizeof(TL::TypeAt<TYPELIST_2(int, double), 1>::Result) ==
         sizeof(double));
  assert(sizeof(TL::TypeAt<type_4, 3>::Result) == sizeof(long long));
  std::cout << TL::IndexOf<type_4, char>::value << std::endl;
  std::cout << TL::IndexOf<type_4, std::string>::value << std::endl;
  using append_list = TL::AppendList<type_4, type_3>::Result;
  std::cout << TL::Length<append_list>::value << std::endl;
  return 0;
}