#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

/*
class Notepad{
public:
    string w;
    int k;

    // Notepad(){  w = ""; k = 0; }
    Notepad(string w="", int k=0){  this->w = w; this->k = k; }
    ~Notepad(){     }    
};

vector<Notepad> v;
*/
int q, n;
string s;

stack<string> st;

void Append(string w){
    s = s+w;
    st.push(s);
}

void Delete(int k){
    int l = s.size();
    s = s.substr(0,l-k);
    st.push(s);
}

void Print(int k){
    cout<<s[k-1]<<"\n";
}

void Undo(){
    st.pop();
    s = st.top();
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

    s = ""; 
    
    st.push(s);
    cin>>q;
    
    string w;
    int k; 

    while(q--){
        cin>>n;
        if(n == 1){
            cin>>w;
            Append(w);
        }else if(n == 2){
            cin>>k;
            Delete(k);
        }else if(n == 3){
            cin>>k;
            Print(k);
        }else if(n == 4){
            Undo();
        }else{  }
    }


    return 0;
}
