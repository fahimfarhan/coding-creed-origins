#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    //n = 1<<16;
    //cout<<n<<"\n";
    cin>>n;

    bool b = true;
    if(n<2){    b = false ; } 
    else if( (n!=2) && (n%2) == 0 ){   b = false; }
    if(b == true){
        for(int i=3; i*i<=n; i+=2){
            if( (n%i) == 0 ){  b = false; break; }
        }
    }

    if(b){  cout<<"true\n" ;    }
    else{   cout<<"false\n";    }

    return 0;
}