#include <bits/stdc++.h>


#include <cstdlib>
#include <ctime>

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

int dp[10][10];
int mine[10][10];

void init(){

    srand(time(NULL));
    //return 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int random_number = std::rand(); // rand() return a number between ​0​ and RAND_MAX
            random_number = random_number%10;
            mine[i][j] = random_number;
            dp[i][j] = -1;
        }
    }
}

bool isvalid(int x, int y){
    return ((x>=0) && (x<10) && (y>=0) && (y<10));
}

int f(int i, int j){
    int ret = 0;
    if(!isvalid(i,j)){    return 0;   }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }else{
        dp[i][j] = mine[i][j]+f(i-1, j+1)+f(i, j+1)+f(i+1, j+1);
        return dp[i][j];
    }
    return 0;
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

    init();

    int x=2, y=3;

    int result = f(x,y);

    cout<<result<<"\n";

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<dp[i][j]<<" , ";
        }cout<<"\n";
    }


    return 0;
}
