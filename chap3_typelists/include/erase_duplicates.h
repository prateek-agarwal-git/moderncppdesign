#pragma once
#include "erase.h"
#include "type_lists.h"
namespace TL {
template <typename TList> struct NoDuplicates;
template<>
struct NoDuplicates<NullType> {
  using Result = NullType;
};
template <typename Head, typename Tail>
struct NoDuplicates<TypeList<Head, Tail>> {
  using L1 = typename NoDuplicates<Tail>::Result;
  using L2 = typename Erase<L1, Head>::Result;
  using Result = TypeList<Head, L2>;
};

} // namespace TL