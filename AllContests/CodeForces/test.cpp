#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[5] = {10,20,30,40,50};
    int x = lower_bound(a,a+5,10)-a;
    cout<<x<<endl;
}