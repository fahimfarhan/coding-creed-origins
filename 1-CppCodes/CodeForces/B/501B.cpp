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

int n; 
map<string , string> edge;
set<string> newId;

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
    cin>>n;
    string New, Old;
    for(int i=0; i<n; i++){ 
        cin>>Old>>New;
        edge[Old] = New;
        newId.insert(New);    
    }

    vector< pair<string , string > > output;

    map<string, string>::iterator it;

    string s1, s2, curr;
    for(it = edge.begin(); it!=edge.end(); it++){
        curr = it->first;
        s1 = curr;
        if(newId.count(curr)>0){    continue;   }
        else{
            while(edge.count(curr)){
                curr = edge[curr];
            }
        }
        output.push_back({s1,curr});
    }

    n = output.size();
    cout<<n<<"\n";

    for(int i=0; i<n; i++){
        cout<<output[i].first<<" "<<output[i].second<<"\n";
    }

    return 0;
}
