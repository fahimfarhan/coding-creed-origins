#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvalid;

int T, N;

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

    cin>>T;
    //string *s;
    
    for(int t=1; t<=T; t++){
        cin>>N;
        //s = new string[N+1];
        //isvalid = new bool[N+1];
        vector<string> s;
        set<int> st;
    
        string temp;
        for(int i=0; i<N; i++){ cin>>temp;
        //s[i]=temp; 
        s.push_back(temp);
         }

        
        int li, lj;
        char ci, cj;
        for(int i=0; i<N-1; i++){
            for(int j=i+1; j<N; j++){
                li = s[i].size(); lj=s[j].size();
                ci = s[i][li-1];
                cj = s[j][lj-1];
                if(ci==cj){
                   st.insert(i); st.insert(j); 
                }
            }
        }
        int size = st.size();
        cout<<"Case #"<<t<<": "<<size<<"\n";
        //delete[] s;
    }
    return 0;
}
