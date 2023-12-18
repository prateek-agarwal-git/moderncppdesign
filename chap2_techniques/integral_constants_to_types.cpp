#include <iostream>
// used for typifying an integral constant
template <int v> struct Int2Type {
  enum { value = v };
};
// call one of different functions at compile time (compile time constant)
// runtime dispatch requires all the branches to compile successfully. Although
// this is taken care of in new C++ by using constexpr

template <typename T, bool isPolymorphic> class NiftyContainer {
private:
  void DoSomething(T *pObj, Int2Type<true>) {
    std::cout << "polymorphic" << std::endl;
    // T* pNewObj = pObj->Clone();
  }

  void DoSomething(T *pObj, Int2Type<false>) {
    std::cout << "non polymorphic" << std::endl;
    // T* pNewObj = new T{*pObj};
  }

public:
  void DoSomething(T *pObj) { DoSomething(pObj, Int2Type<isPolymorphic>()); }
};

int main() {
  NiftyContainer<int, true> N;
  int x;
  N.DoSomething(&x);
  NiftyContainer<int, false> F;
  F.DoSomething(&x);
  return 0;
}