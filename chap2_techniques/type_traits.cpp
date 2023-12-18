#include <cstdint>
#include <vector>
#include <iostream>
#include "include/type_traits.h"
template <typename InIt, typename  OutIt>
OutIt Copy(InIt first, InIt last, OutIt result){
    for (; first != last; ++first,++result){
        *result = *first;
    }
}

void BitBlast(const void* src, void* dest,size_t bytes);

// Are Init and OutIt regular pointers (instead of iterators)?
// The type to which they point is copyable with bitwise copy?

// Pointer traits


int main(){
    const bool iterIsPtr = TypeTraits<std::vector<int>::iterator>::isPointer;
    std::cout << "vector<int>::iterator is "<< (iterIsPtr? "fast":"smart") << "\n";
    const bool is_type_a_reference = TypeTraits<int&>::isReference;
    std::cout << "int& is a " << (is_type_a_reference? "reference": "not a reference")<< "\n";

    const bool is_int_a_reference = TypeTraits<int>::isReference;
    std::cout << "int is a " << (is_int_a_reference? "reference": "not a reference")<< "\n";
    return 0;
}