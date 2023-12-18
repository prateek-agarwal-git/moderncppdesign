#pragma once
struct NullType{};

template <typename T>
class TypeTraits{
    private:
    template <typename U> struct PointerTraits{
        enum {result = false};
        using PointeeType = NullType;
    };
    template<typename U> struct PointerTraits<U*>{
        enum {result = true};
        using PointeeType = U;
    };
    template <typename U> struct ReferenceTraits{
        enum {result = false};
        using ReferencedType = NullType;
    };
    template <typename U> struct ReferenceTraits<U&>{
        enum {result = true};
        using ReferencedType = U;
    };

    template <class U> struct PToMTraits{
        enum {result = false};
    };

    template <typename U, typename V>
    struct PToMTraits<U V::*> {
        enum {result = true};
    };
    template <typename U> struct UnConst{
        using Result=U;
    }:
    template <typename U> struct UnConst<const U>{
        using Result=U;
    };

    public:
    enum {isPointer = PointerTraits<T>::result,isReference = ReferenceTraits<T>::result};
    using PointeeType = typename PointerTraits<T>:: PointeeType;
    using ReferencedType = typename ReferenceTraits<T> :: ReferencedType;
    using NonConstType = typename UnConst<T>::Result;
};


