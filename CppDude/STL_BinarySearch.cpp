#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int a[5] = {3,10,8,6,11};
    int n = 5;
    // binary_search()
    //sort(a,a+n);

    bool b = binary_search(a, a+n, 2);
    cout<<"without sorting it wont work!"<<b<<"\n";
    // after sorting
    sort(a,a+n);
    b = binary_search(a, a+n, 2);
    cout<<"after sorting "<<b<<"\n";

    // lower_bound & upper bound
    cout<<*lower_bound(a,a+n, 1)<<"\n-----------\n";

    cout<<*upper_bound(a,a+n, 1)<<"\n";
    cout<<*upper_bound(a,a+n, 10)<<"\n";
    cout<<*upper_bound(a,a+n, 3)<<"\n";
    cout<<*upper_bound(a,a+n, 11)<<"\n---------\n";


    /******   Get the position/index    ***********/
    cout<<upper_bound(a,a+n, 1)-&a[0]<<"\n";
    cout<<upper_bound(a,a+n, 10)-a<<"\n";
    cout<<upper_bound(a,a+n, 3)-a<<"\n";
    cout<<upper_bound(a,a+n, 11)-a<<"\n";

    return 0;
}