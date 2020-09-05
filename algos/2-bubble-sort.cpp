#include <bits/stdc++.h>
#include <shared_mutex>
using namespace std;


// void bubbleSort(vector<int>& v) {
//     for(int i=0; i<v.size()-1; i++) {  //a -1 cz we'll be doing a v[i] < v[i+1] this kinda comparison 
//         for(int j=0; j<v.size() - 1 - i; j++) {
//             if(v[j]>v[j+1]) {
//                 swap(v[j], v[j+1]);
//             }
//         }
//     }
// }

void onlyBubbleSort(vector<int>& v) {  // geeksForGeeks
    for(int i=1; i<v.size(); i++) {
        for(int j=1; j<v.size() - i; j++) {
            if(v[j-1]>v[j]) {
                swap(v[j-1], v[j]);
            }
        }
    }
}

int bubbleSort(vector<int>& v) {
    int kount = 0;
    for(int i=1; i<v.size(); i++) {
        for(int j=1; j<v.size(); j++) {
            if(v[j-1]>v[j]) {
                swap(v[j-1], v[j]);
                kount++;
            }
        }
    }
    return kount;
}

int main() {
    vector<int> a = {64, 34, 25, 12, 22, 11, 90}; 
    int kount = bubbleSort(a);
    for(auto i : a) {
        cout<<i<<" ";
    }cout<<"\n";
    cout<<"Step kount = "<<kount<<"\n";
    return 0;
}