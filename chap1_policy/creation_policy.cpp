#include "include/creation_policy.h"

template <typename CreationPolicy>
struct WidgetManager : public CreationPolicy {
  WidgetManager() {}
  void count() { int *x = CreationPolicy::Create(); }
};

int main() {
  using MyWidgetMgr = WidgetManager<OpNewCreator<int>>;
  MyWidgetMgr m;
  int *n = m.Create();
  return 0;
}