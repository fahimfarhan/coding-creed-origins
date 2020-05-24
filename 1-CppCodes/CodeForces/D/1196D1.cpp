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

    ll q,n,k, mycount, minimus;
    string s, temp1="RGB";
    string inf1="", inf2="", inf3="";
    
    for(int i=0; i<=2000; i++){
        inf1+=temp1[i%3];
    }

    inf2 = "B"+inf1;
    inf3 = "G"+inf2;

    string temp3, temp2;
    cin>>q;
    while(q--){
        cin>>n>>k;
        cin>>s;
        temp1 = "";
        temp1 = inf1.substr(0,k);
        temp2 = inf2.substr(0,k);
        temp3 = inf3.substr(0,k);

        minimus = INT_MAX;
        for(int i=0; i<=(n-k); i++){
            mycount = 0;
            for(int j=0; j<k; j++){
                if(s[i+j]!=temp1[j]){    mycount++;}
            }
            minimus = min(mycount, minimus);

            mycount=0;
            for(int j=0; j<k; j++){
                if(s[i+j]!=temp2[j]){    mycount++;}
            }
            minimus = min(mycount, minimus);

            mycount=0;
            for(int j=0; j<k; j++){
                if(s[i+j]!=temp3[j]){    mycount++;}
            }
            minimus = min(mycount, minimus);
            
            if(minimus == 0){   break; }
        }
        cout<<minimus<<"\n";

    }


    return 0;
}