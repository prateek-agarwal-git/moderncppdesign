#pragma once
#include "type_lists.h"
// input: typelist and index i
// output : inner type result
// if typelist head is  T and index is zero then T is the result.
// else calculate indexed access in the tail typelist with index as i -1
// if Tlist is null then the error reduce to compile time.

namespace TL{
template <typename TList, unsigned int i> struct TypeAt;

template <typename Head, typename Tail>
struct TypeAt<TypeList<Head, Tail>, 0>{
    using Result= Head;
};

template <typename Head, typename Tail, unsigned int i>
struct TypeAt<TypeList<Head, Tail>,i >{
    using Result = typename TypeAt<Tail,i-1>::Result;
};



}

