#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	
    long long n1,a1,ans1, minimus1,sum1,s1;
    cin>>n1>>s1;
    minimus1 = INT_MAX;
    sum1 = 0;
    for(int i=0; i<n1; i++){
        cin>>a1;
        sum1+=a1;
        minimus1 = min(minimus1, a1);
    }

    if(s1 > sum1){
        cout<<"-1\n";
    }else{
        sum1-=minimus1;
        long long temp1 = sum1 - s1;
        ans1 = -minimus1 + temp1;
    cout<<ans1<<"\n";
	
    }

    return 0;
}
