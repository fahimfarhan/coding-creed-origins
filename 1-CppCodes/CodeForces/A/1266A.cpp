/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n;
    for(int j=0; j<n; j++){
        cin>>s;
        int zeroKount = 0;
        int sum = 0;
        int evenKount = 0;
        int temp = 0;
        for(int i=0; i<s.size(); i++){
            temp = s[i] - '0';
            sum = sum + temp;
            if(s[i]=='0'){  zeroKount++;    }
            else{   
                if((temp>0)&&((temp&1)==0)){  evenKount++;}   
            }
        }
        bool b = false;
        
        // is divisible by 10?
        if(sum == 0){ 
            b = true; 
        }
        else{
            if((zeroKount>0)){
            // ok. is sum divisible by 3
                if( (sum%3) == 0){
                    // is sum even?
                    if( ( evenKount > 0)){
                        b = true;
                    }else if(zeroKount>=2){
                        b = true;
                    }else{
                        b = false;
                    }
                }
            }
        }
        if(b){  cout<<"red\n";  }
        else{   cout<<"cyan\n"; }


    }

    return 0;
}

