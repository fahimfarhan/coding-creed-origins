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

    string s;
    stack<char> st;
    int n;
    char ch;
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++){
        ch = s[i];
        if(st.empty()){ st.push(ch);  }
        else if( (st.top()=='(') && (ch == ')')  ){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    if(st.size()==0 ){
        cout<<"Yes\n";
    }else if(st.size()==2){
        ch = st.top(); st.pop();
        if(ch != st.top()){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else{
        cout<<"No\n";
    }

    // while(!st.empty()){ cout<<st.top()<<""; st.pop(); }


    return 0;
}