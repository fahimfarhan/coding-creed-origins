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

    int N, maximus = 0;
    string s[25];

    cin>>N;
    //s = new string[N+1];
    for(int i=0; i<N; i++){    cin>>s[i]; maximus = max(maximus, (int)s[i].size());      }

    int temp=0;
    for(int i=0; i<N; i++){
        temp = s[i].size();

        if((temp&1)==2){
            s[i]+='a';
            s[i]+='\n'; 
            temp++;
            temp = maximus-temp;  
            temp=temp>>1;
            for(int j=0; j<temp; j++){  s[i] = ' '+s[i];    }
        }
        else if((temp&1)==0){   
            s[i][temp-1]='\n';  
            temp--;
            temp = maximus-temp;  
            temp=temp>>1;
            for(int j=0; j<temp; j++){  s[i] = ' '+s[i];    }
        }else{
            s[i]+='\n';
            temp = maximus-temp;  
            temp=temp>>1;
            for(int j=0; j<temp; j++){  s[i] = ' '+s[i];    }
        }
    }

    for(int i=0; i<N; i++){ cout<<s[i]; }

    //delete[] s;
    return 0;
}