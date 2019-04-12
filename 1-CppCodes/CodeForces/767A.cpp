#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int> st;
    int n, *a;
    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++){    cin>>a[i];  }
    st.push(a[0]);
    int spaces = 0;
    for(int i=01; i<n; i++){
        if(a[i]<a[i-1]){
            spaces = st.size()-1;
            while(spaces--){    cout<<"\n"; }
            
            while(!st.empty()){ cout<<st.top()<<" ";st.pop();    } cout<<"\n";
            
        }st.push(a[i]);
    }
    spaces = st.size()-1;
    while(spaces--){    cout<<"\n"; }
    
    while(!st.empty()){ cout<<st.top()<<" ";st.pop();    } cout<<"\n"; 
    
    if(!a)delete[] a;
    return 0;
}
