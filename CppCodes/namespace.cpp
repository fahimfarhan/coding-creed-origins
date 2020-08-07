#include <bits/stdc++.h>

using namespace std;

namespace mynamespace1{
    class A{
        private:
        public:
        A(){
            cout<<"this is A\n";
        }
        void lol(){ cout<<"inside mynamespace1\n";      }
        ~A(){}
    };
}


namespace mynamespace2{
    class A{
        private:
        public:
        A(){
            cout<<"this is A\n";
        }
        void lol(){ cout<<"inside mynamespace2\n";      }
        ~A(){}
    };
}

int main(){
    mynamespace1::A *a = new mynamespace1::A();
    a->lol();

    if(!a)delete a;
    return 0;
}