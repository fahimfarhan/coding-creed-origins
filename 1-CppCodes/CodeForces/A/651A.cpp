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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int mycount=0,x; double a1,a2,temp;

    cin>>a1>>a2;
    if(a2<a1){ 
        temp=a2; 
        a2=a1;
        a1=temp;
    }

    //if( (a1==1) && (a2==1) ){   cout<<0<<"\n";; exit(0);    }

    while( (a1>0) && (a2>0) ){
        // a1+x > a2-2x => 3x > a2-a1 => x > (a2-a1)/3 => x= ceil((a2-a1)/3)
        if(a1!=a2){
            x = ceil(1.0*(a2-a1)/3);
        }else{  x=1; }
        a1 = a1+x; a2=a2-(x<<1);

        if(a2<0){   break;  }
        
        temp=a2; 
        a2=a1;
        a1=temp;
        mycount+=x;

    }
    cout<<mycount<<"\n";
    return 0;
}
