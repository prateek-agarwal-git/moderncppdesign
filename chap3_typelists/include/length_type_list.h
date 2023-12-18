#pragma once
#include "type_lists.h"
namespace TL{
    template <typename TList> struct Length;
    template <> struct Length<NullType>{
        enum {value = 0};
    };
    template <typename T, typename U> 
    struct Length<TypeList<T,U>>{
        enum {value = 1 + Length<U> :: value};
    };
}