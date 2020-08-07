#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(const string& in, int lo, int hi){
    while(lo<hi){
        if(in[lo]!=in[hi]){ return false;   }
        lo++;
        hi--;
    }
    return true;
}

int main()
{


    return 0;
}