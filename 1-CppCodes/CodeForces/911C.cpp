#include <bits/stdc++.h>

using namespace std;

int k[3];
bool b = false;

int main(){
    cin>>k[0]>>k[1]>>k[2];

    //One of ki is equal to 1;
    for(int i=0; i<3; i++){ if(k[i]==1){    b = true;   }   }
    //At least two of ki are equal to 2;
    int twoCount = 0;
    for(int i=0; i<3; i++){ if(k[i] == 2){  twoCount++; }   }
    if(twoCount >=2){   b = true;   }
    //All ki equal 3;
    if( (k[0]==k[1]) && (k[1]==k[2]) && (k[2] == 3) ){  b = true; }
    //k = {2, 4, 4}. 
    sort(k,k+3);
    if( (k[0] == 2) && (k[1] == 4) && (k[2] == 4) ){    b = true; }
    if(b==true){    cout<<"YES\n";  }
    else{   cout<<"NO\n";   }

    return 0;
}