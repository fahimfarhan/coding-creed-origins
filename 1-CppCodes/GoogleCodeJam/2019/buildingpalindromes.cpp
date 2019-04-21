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

bool ispalindrome(string s){
    int myccount=0;
    if(s.size()==1){    return true; }
    int len = s.size(); 
    sort(s.begin(),s.end());
    int i=0;
    while(i<len-1){
        if(s[i]==s[i+1]){
            s[i]='-'; s[i+1]='-';
            i+=2;
        }else{
            i=i+1;
        }
    }
    i=0;
    myccount=0;
    for(i=0; i<len; i++){   if(s[i]!='-'){myccount++;} }

    bool ret = true;
    if(myccount<=1){    return true; }
    else{   return false; }
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

    string s, b;
   

    int T,N,Q,l,r,len, mycount;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N>>Q;
        cin>>s;
        mycount=0;
        while(Q--){
            cin>>l>>r;
            l--; r--;
            len = r-l+1;
            b = "";
            b = s.substr(l,len);
            if(ispalindrome(b)){
                mycount++;
            }
            //cout<<b<<"\n";
        }
        cout<<"Case #"<<t<<": "<<mycount<<"\n";

    }
    
    return 0;
}
