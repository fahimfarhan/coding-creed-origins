#include <iostream>

using namespace std;

int findDuplicateNumber(int num[]){
    int hare = num[0];
    int tortoise = num[0];

    while(true){
        tortoise = num[tortoise];
        hare = num[num[hare]];

        if(tortoise == hare)
            break;
    }

    int ptr1 = num[0];
    int ptr2 = num[tortoise];

    while(ptr1 != ptr2){
        ptr1 = num[ptr1];
        ptr2 = num[ptr2];
    }

    return ptr1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[] = {3,1,3,4,2};

    int duplicate = findDuplicateNumber(a);
    cout<<duplicate<<"\n";
    return 0;
}