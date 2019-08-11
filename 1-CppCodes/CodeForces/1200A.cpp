/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

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
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; string s="", t="";
    cin>>n;
    cin>>s;

    for(int i=0; i<10; i++){ t=t+'0';    }
    
    for(int i=0; i<n; i++){
        switch (s[i])
        {
        case 'L':{
            /* code */
            for(int j=0; j<10; j++){ if(t[j]=='0'){  t[j] = '1'; break; }  }
            break;
        }
        case 'R':{
            /* code */
            for(int j=9; j>=0; j--){ if(t[j]=='0'){  t[j] = '1'; break; }  }
            break;
        }
        default:{
            int temp = s[i] - '0';
            t[temp] = '0';
            break;
        }
            
        }
    }

    cout<<t<<"\n";
    
    return 0;
}