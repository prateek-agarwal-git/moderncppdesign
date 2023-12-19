#pragma once
#include "type_lists.h"

namespace TL{

template <typename TList, typename T> struct Erase;

template <typename Tail, typename T>
struct Erase<TypeList<T, Tail>, T> {
    using Result=Tail;
    // using Result = typename EraseAll<Tail,T>::Result;
};
template <typename T>
struct Erase<NullType, T>{
    using Result=NullType;
};

template <typename Head, typename Tail, typename T>
struct Erase<TypeList<Head, Tail>, T>{
 using Result = TypeList<Head, typename Erase<Tail,T>::Result>;
};
}