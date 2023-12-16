#pragma once
#include <cstdlib>

template <typename T> struct OpNewCreator {
  static T *Create() { return new T; }

protected:
  ~OpNewCreator() {
    // this destructor is made protected so that the instantiated class is not
    // degraded to policy class and destructor is called. Another option is to make such destructors virtual - this will increase the memory footprint of the application.
  }
};
template <typename T> struct MallocCreator {
  static T *Create() {
    void *buf = std::malloc(sizeof(T));
    if (!buf)
      return nullptr;
    return new (buf) T;
  }
};

template <typename T> struct PrototypeCreator {
  PrototypeCreator(T *pObj= nullptr) : pPrototype_(pObj) {}
  T *Create() { return pPrototype_ ? pPrototype_->Clone() : nullptr; }
  T *GetProtoType() { return pPrototype_; }
  void SetPrototype(T *pObj) { pPrototype_ = pObj; }

private:
  T *pPrototype_;
};