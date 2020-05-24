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

vector<pair<int,int> > points;
bool mp[2001][2001];

int main(int argc, char const *argv[])
{
    /* code */
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<2001; i++){
        for(int j=0; j<2001; j++){
            mp[i][j] = false; 
        }
    }

    int n, x,y, count=0; 
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        x=x+1000; y=y+1000;
        points.push_back({x,y});
        mp[x][y] = true;
    }

    count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            x = points[i].first + points[j].first;
            y = points[i].second + points[j].second;

            if( ( (x&1) == 0) && ( (y&1) == 0) ){
                x = x>>1; y = y>>1;
                if(mp[x][y]){
                    count++;
                }
            }
        }
    }

    //count=count>>1;

    cout<<count<<"\n";

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/