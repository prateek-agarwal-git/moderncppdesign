#pragma once

struct NullType{};
template <typename T, typename U>
struct TypeList
{
    using Head = T;
    using Tail = U;
};

using CharList = TypeList<char, TypeList<signed char,unsigned char>>;
using IntTypeOnly = TypeList<int, NullType>;