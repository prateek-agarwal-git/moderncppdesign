template <typename T, bool isPolymorphic>
struct NiftyContainerValueTraits{
    using ValueType  = T*;
};
template <typename T>
struct NiftyContainerValueTraits<T,false>{
    using ValueType = T;

};

template <typename T,bool isPolymorphic>
class NiftyContainer{
using Traits = NiftyContainerValueTraits<T, isPolymorphic>;
using ValueType = Traits::ValueType ;


};