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

int f(const int& first,const int&  second){
    if((first==1) && (second==2)){    return 4;   }
    if((first==2) && (second==1)){    return 4;   }
    if((first==1) && (second==3)){    return 3;   }
    if((first==3) && (second==1)){    return 3;   }
    return -1;
}

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

    int n, *a;
    cin>>n;
    a = new int[n+1];

    for(int i=0; i<n; i++){ cin>>a[i];  }
    
    ll ans=0, temp=0;
    for(int i=1; i<n; i++){ 
        temp = f(a[i-1],a[i]);
        //cerr<<a[i-1]<<" "<<a[i]<<" "<<temp<<"\n";
        if(temp == -1){  cout<<"Infinite\n"; exit(0);  }
        ans+=temp;
    }


        cout<<"Finite\n";
        cout<<ans<<"\n";
    delete[] a;
    return 0;
}
