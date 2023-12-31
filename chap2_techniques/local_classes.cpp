
class Interface{
public:
virtual void fun() = 0;    
};
template <typename T, typename P>
Interface* MakeAdapter(const T& obj, const P& arg){
    class Local: public Interface{
        public:
        Local (const T&obj, const P& arg): obj_(obj), arg_(arg){}
        void fun() override{
            obj_.Call(arg_);
        }
        private:
        T obj_;
        P arg_;
    };
    return new Local(obj,arg);

}


int main(){
    return 0;
}
