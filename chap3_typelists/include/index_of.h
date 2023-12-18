#pragma once
#include "type_lists.h"

namespace TL {
// input type list, type
// output index (-1 if type not present.)

template <typename TList, typename T> struct IndexOf;

template <typename T> struct IndexOf<NullType, T> {
  static constexpr int value = -1;
};
template <typename Tail, typename T> struct IndexOf<TypeList<T, Tail>, T> {
  static constexpr int value = 0;
};

template <typename Head, typename Tail, typename T> struct IndexOf<TypeList<Head, Tail>, T> {
  static constexpr int value = (IndexOf<Tail, T>::value == -1)? -1 : (1+ IndexOf<Tail, T>::value);
};
} // namespace TL
