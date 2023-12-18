#include <iostream>
#include "include/length_type_list.h"
#include "include/type_list_macros.h"
#include "include/type_at.h"
#include <cassert>


  

using type_4 = TYPELIST_4(int, double, char , long long);
int main(){
   std::cout << TL::Length<TYPELIST_1(int)>::value  << std::endl;
   std::cout << TL::Length<TYPELIST_2(int, double)>::value  << std::endl;
   std::cout << TL::Length<TYPELIST_3(int, double, char)>::value  << std::endl;
   std::cout << TL::Length<TYPELIST_4(int, double, char , long long)>::value  << std::endl;


    assert(sizeof (TL:: TypeAt<TYPELIST_2(int,double),1>::Result) == sizeof (double));
    assert(sizeof (TL:: TypeAt<type_4,3>::Result) == sizeof (long long));

    return 0;
}