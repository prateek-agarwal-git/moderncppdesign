#include <iostream>
#include <vector>
template <typename T, typename U> class Conversion {
  using Small = char;
  struct Big {
    char dummy[2];
  };
  static Small Test(U);
  static Big Test(...);
  static T MakeT();

public:
  enum  {exists = sizeof(Test(MakeT())) == sizeof(Small)};
};
class B{};
class A: public B{};


int main(){
    std::cout << Conversion<double,int>::exists << std::endl;
    std::cout << Conversion<A,B>::exists << std::endl;
    std::cout << Conversion<size_t,std::vector<int>>::exists << std::endl;
    std::cout << Conversion<B,A>::exists << std::endl;
    return 0;
}