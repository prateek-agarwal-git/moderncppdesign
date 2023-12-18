#include <iostream>
template< bool flag, typename T, typename U>
struct Select{
    using Result=T;
};

template <typename T, typename U>
struct Select<false, T, U>{
    using Result=U;
};
int main(){
    Select<true, int, double>::Result x;
    std::cout << sizeof(x)<< std::endl;

    Select<false, int, double>::Result y;
    std::cout << sizeof(y)<< std::endl;
    return 0;
}