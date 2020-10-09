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

    int T;
    cin>>T;
    vector<string> path;
    string s, a;

    for(int t=0; t<=T; t++){
        getline(cin,s);
        if(s == "pwd"){
            cout<<"/";
            for(int i=0; i<path.size(); i++ ){
                cout<<path[i]<<"/";
            }cout<<"\n";
        }
        else{
            if(s.size()>3)
            {
                s = s.substr(3);
                if(s[0]=='/'){
                    s = s.substr(1);
                    while(!path.empty()){   path.pop_back();    }
                }
                for(int i=0; i<s.size(); i++){
                    if(s[i]=='/'){  s[i]=' '; }
                }
                //cout<<"here: "<<s<<"\n";
                istringstream iss(s);
                
                while(iss>>a){
                    if(a==".."){  path.pop_back();}
                    else{  path.push_back(a);  }
                }
            }
        }
    }

    return 0;
}
