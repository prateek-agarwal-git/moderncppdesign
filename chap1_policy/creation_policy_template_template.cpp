#include "include/creation_policy.h"

template <template <typename> class CreationPolicy>
class IntManager : public CreationPolicy<int> {
public:
  IntManager() { int *x = CreationPolicy<int>::Create(); }
  //   Example of Switch Prototype is commented out as Clone is not defined for
  //   int.
  //  void SwitchPrototype(int *x) {
  //    CreationPolicy<int> &myPolicy = *this;
  //    myPolicy.SetPrototype(x);
  //  }
};

int main() {
  using MyIntMgr = IntManager<OpNewCreator>;
  MyIntMgr m;
  int *n = m.Create();

  using PMgr = IntManager<PrototypeCreator>;
  //   PMgr p;
  //   p.SwitchPrototype(n);
  return 0;
}