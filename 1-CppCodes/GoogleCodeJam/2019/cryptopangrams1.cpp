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

    int T, N, L; ll a, first, second, third;
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>N>>L;
        cin>>a;
        int stop = sqrt((int)a);
        for(int i=3; i<=stop; i+=2){
            if( (a%i) ==0){    first = i; second = a/i;    }
        }

        vector<ll> originalOrder; set<ll> sortedOrder;

        cin>>a;
        if( (a%first) == 0){   
            first = first^second;
            second = first^second;
            first = first^second;
        }
        third = a/second;
        originalOrder.push_back(first); originalOrder.push_back(second); originalOrder.push_back(third);
        sortedOrder.insert(first); sortedOrder.insert(second); sortedOrder.insert(third);

        for(int i=2; i<L; i++){
            cin>>a;
            third = a/third;
            originalOrder.push_back(third);
            sortedOrder.insert(third); 
        }

        map<ll, char> mp; 
        int pos = 0;
        set<ll>::iterator it;
        for(it=sortedOrder.begin(); it!=sortedOrder.end(); it++)
        {    a = (*it); mp[a] = 'A'+pos; pos++;    }
        
        cout<<"Case #"<<t<<": ";
        int len123 = originalOrder.size();
        for(int i=0; i< len123; i++){
            a = originalOrder[i];
            cout<<mp[a];
        }cout<<"\n";
    }
    return 0;
}
