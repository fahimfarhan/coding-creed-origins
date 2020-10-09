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

    int temp,n, maximus=-1; ll k;
    int a;
    queue<int> q;
    cin>>n>>k;
    //a = new int[2*n+1];

    for(int i=0; i<n; i++){  cin>>a; q.push(a);  maximus = max(maximus, a); }
    if(k>=n){  cout<<maximus<<"\n";  }
    else{
        maximus = q.front();
        q.pop();
        //for(int i=0; i<n; i++){
        int flag = 0;
        while(true){
            int j=0;     
            for(j=0; j<(k-flag); j++){
                a = q.front(); q.pop();
                if(maximus>a){   q.push(a); }
                else{   
                    maximus = maximus^a;
                    a = maximus^a;
                    maximus  = maximus^a;
                    q.push(a);
                    flag = 1;
                    j=0; 
                    break;
                }    
            }
            if(j==(k-flag) ){   break; }
        }
        cout<<maximus<<"\n";
    }

    return 0;
}