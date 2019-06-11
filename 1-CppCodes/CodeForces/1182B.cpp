#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

char **c;


int h,w;
int totalStarCount=0;

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

    cin>>h>>w;
    c = new char*[h+1];
    for(int i=0; i<=h; i++){ c[i] = new char[w+1];     }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>c[i][j];
            if(c[i][j] == '*'){ totalStarCount++; }
            
        }
    }

    if(totalStarCount<5){
        cout<<"NO\n";
        exit(0);
    }
    
    int temp, up, down, left, right;
    bool flag = false;

    for(int i=01; i<h-1; i++){
        for(int j=1; j<w-1; j++){
            if(c[i][j] == '*'){
                temp = 1; up = 0; down = 0; left = 0; right = 0;
                // check up
                for(int k = i-1; k>=0; k--){
                    if(c[k][j]=='*'){   up++; }
                    else{   break; }
                }
                // check down
                for(int k = i+1; k<h; k++){
                    if(c[k][j]=='*'){   down++; }
                    else{   break; }
                }

                // check left
                for(int k = j-1; k>=0; k--){
                    if(c[i][k]=='*'){   left++; }
                    else{   break; }
                }
                // chwck right
                for(int k = j+1; k<w; k++){
                    if(c[i][k]=='*'){   right++; }
                    else{   break; }
                }
                if(up==0 || down==0 || left==0 || right==0){    continue; }
                else{
                    temp = temp + up+down+left+right;
                    if(temp == totalStarCount){
                        cout<<"YES\n";
                        flag = true;
                        break;
                    }
                } 
            }
        }
    }
    if(!flag){
        cout<<"NO\n";

    }
    for(int i=0; i<=h; i++){ delete[] c[i];     }
    delete[] c;
    return 0;
}