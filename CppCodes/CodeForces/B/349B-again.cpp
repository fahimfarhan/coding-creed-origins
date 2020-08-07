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

    int v, minimus, index;
    int a[10];
    minimus = INT_MAX;
    cin>>v;
    for(int i=1; i<=9; i++){    
        cin>>a[i]; 
        if(a[i]<minimus){   minimus = a[i]; index = i; }
    }

    sring s="";
    int d = v/minimus;
    int r = v%minimus;

    for(int i=0; i<d; i++){ s=s+(char)('0'+index);}

    int len = s.size();

    int paintInHand;
    for(int i=1; i<10; i++){
        if(i!=index){
            paintInHand = r + d;
            if(paintInHand>a[i]){
                
            }
            
        }
    }
    



    
    return 0;
}
