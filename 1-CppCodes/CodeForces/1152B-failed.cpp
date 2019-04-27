#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll unsigned int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int getNumberOfOnes(const ll& m){
    ll n = m;
    int mycount = 0;
    while (n>0){
        mycount = mycount+(n&1);
        n = (n>>1);
    }
}




int getLen(const ll& m,const ll& p ){
    ll q=p;
    ll n=m;
    int mycount = 0;
    while( q != 0 ){  q = q - (n&1); n=n>>1; mycount++; }
    return mycount;
}

int findLeftMostZeroPosition(const ll& N, const ll& size){
    ll n = size;
    ll retSize = size;
    n = 1<<n;
    while( (N&n) !=0 ){
        n=n>>1;
    }
    retSize = n;
    return retSize;
}

int getNextOddNumber(const ll& input){
    ll ret = input;
    ret = (ret<<1);
    ret = ret - 1;
    return ret;
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
    ll x;
    int len=0;
    int count=0;    
    vector<ll> nextOddNum; 
    cin>>x;
    len = getLen(x, getNumberOfOnes(x));
    ll temp = findLeftMostZeroPosition(x,len);
    while(temp!=0){
        temp = getNextOddNumber(temp);
        nextOddNum.push_back(temp);
        x = x^temp; // step 1 
        x = x+1; // step 2
        temp = findLeftMostZeroPosition(x,len);
    }

    ll mysize = nextOddNum.size();
    mysize = mysize<<1;
    cout<<mysize<<"\n";
    mysize = mysize>>1;
    
    for(int i=0; i<mysize; i++){
        cout<<nextOddNum[i]<<" ";
    }cout<<"\n";

    return 0;
}
