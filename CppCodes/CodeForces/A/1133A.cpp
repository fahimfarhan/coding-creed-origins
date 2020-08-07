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

    int h1,m1, h2,m2, t1,t2,tm;
    char c;

    cin>>h1>>c>>m1;
    cin>>h2>>c>>m2;

    if(h2<h1){  h2+=24; }
    
    t1 = h1*60+m1;
    t2=h2*60+m2;

    tm = (t1+t2)/2;

    h1 = tm/60;
    if(h1>=24){  h1=h1-24; }
    m1=tm%60;
    //cout<<h1<<":"<<m1<<"\n";
    printf("%02d:%02d",h1, m1);
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/