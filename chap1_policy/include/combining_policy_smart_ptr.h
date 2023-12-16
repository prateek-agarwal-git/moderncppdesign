#pragma once
#include <stdexcept>

template <typename T> struct NoChecking {
  static void Check(T *) {}
};
template <typename T> struct EnforceNotNull {
  static void Check(T *ptr) {
    if (!ptr)
      throw std::runtime_error("Null pointer");
  }
};
template <typename T> struct EnsureNotNull {

  static void Check(T *&ptr) {
    if (!ptr)
      ptr = new T{};
  }
};

template <typename T, template <typename> typename CheckingPolicy,
          template <typename> typename ThreadingModel>
class SmartPtr : public CheckingPolicy<T>, public ThreadingModel<SmartPtr> {
  T *operator->() {
    typename ThreadingModel<SmartPtr>::Lock guard(*this);
    CheckingPolicy<T>::Check(pointee_);
    return pointee_;
  }

private:
  T *pointee_;
};
