#pragma once
#include "type_lists.h"

namespace TL {
template <typename TList, typename OldType, typename NewType> struct Replace;

template <typename T, typename U> struct Replace<NullType, T, U> {
  using Result = NullType;
};

template <typename Tail, typename T, typename U>
struct Replace<TypeList<T, Tail>,T, U> {
    using Result = TypeList<U, Tail>;
};

template <typename Head, typename Tail,typename T, typename U>
struct Replace<TypeList<Head, Tail>,T, U> {
    using Result = TypeList<Head, typename Replace<Tail, T, U> ::Result>;
};
} // namespace TL