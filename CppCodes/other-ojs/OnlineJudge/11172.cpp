#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a<b){    cout<<"<\n";    }
        else if(a>b){   cout<<">\n";    }
        else if(a==b){  cout<<"=\n";   }
    }
    return 0;
}