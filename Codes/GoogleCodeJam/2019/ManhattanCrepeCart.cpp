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

    int T,P,Q;
    int x,y; char d;
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>P>>Q;
        map<pair<int,int>,int > mp;
        for(int i=0; i<P; i++){
            cin>>x>>y>>d;
            if(d=='N'){ y++; }
            else if(d=='S'){    y--; }
            else if(d=='E'){ x++; }
            else if(d=='W'){    x--; }
            for(int j=x; j>=0; j--){
                mp[{j,y}]++;
                // if(mp[{j,y}] - mp[{j-1,y}]>1){  break; }
            }
        }

        map<pair<int,int>,int >::iterator it;
        int maximus=0;
        int temp;
        int x1,y1;
        for(it=mp.begin(); it!=mp.end(); it++){
            temp = it->second;
            if(temp>maximus){   maximus=temp; x1=(it->first).first; y1=(it->first).second; }
        }
        for(int i=0; i<x1; i++){    if(mp[{i,y1}]==maximus){    x1=i; break; } }
        cout<<"Case #"<<t<<": "<<x1<<" "<<y1<<"\n";    
    }

    
    return 0;
}
