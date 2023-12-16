#pragma once

template <typename T> class DefaultSmartPointerStorage {
public:
  using PointerType = T *;
  using ReferenceType = T &;

protected:
  PointerType GetPointer() { return ptr_; }
  void SetPointer(T *p) { ptr_ = p; }

private:
  PointerType ptr_;
};

//template <class T, template <typename> typename CheckingPolicy,
//          template <typename> typename ThreadingModel,
//          template <typename> typename Storage = DefaultSmartPointerStorage>
//class SmartPtr;