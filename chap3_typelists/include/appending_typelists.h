#pragma once
#include "type_lists.h"

namespace TL {
template <typename TList1, typename TList2> struct AppendList;
//template <> struct AppendList<NullType, NullType> {
//  using Result = NullType;
//};
template <typename TList> struct AppendList<TList, NullType> {
  using Result = TList;
};
template <typename TList> struct AppendList<NullType, TList> {
  using Result = TList;
};
template <typename Head1, typename Tail1,typename T>
struct AppendList<TypeList<Head1, Tail1>,  T> {
  using Result = TypeList < Head1, typename AppendList<Tail1, T>::Result>;
};
} // namespace TL