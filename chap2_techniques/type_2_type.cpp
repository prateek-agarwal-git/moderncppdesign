#include <string>
// template <typename T, typename U>
// T* Create(const U& arg){
//     return new T(arg);
// }

template <typename T> struct Type2Type { using OriginalType = T; };

template <typename T, typename U> T *Create(const U &arg, Type2Type<T>) {
  return new T(arg);
}

struct Widget {
 template <typename T> Widget(const T &arg, int a) {}
};

template <typename U> Widget *Create(const U &arg, Type2Type<Widget>) {
 return new Widget(arg, -1);
}


int main(){
    std::string* x = Create("hello", Type2Type<std::string>());
    Widget* w = Create(-1, Type2Type<Widget>());
    return 0;
}
