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

    int n, count; 
    count=0; 
    char ch;
    map<char, queue<int> > left;
    map<char, queue<int> > right;
    queue<pair<int, int> > q;
    
    cin>>n; 
    {
        string s1, s2;
        cin>>s1; 
        cin>>s2;

        
        for(int i=0; i<n; i++){
            ch = s1[i];
            left[ch].push(i+1);
            ch = s2[i];
            right[ch].push(i+1);
        }

    }
    

    // case 1: a--a 
    ch = 0;
    int stop=0;
    int a,b;
    for(int i=0; i<26; i++){
        ch = 'a'+i;
        stop = min( left[ch].size() , right[ch].size() );
        
        for(int j=0; j<stop; j++){
            a = left[ch].front();
            b = right[ch].front();

            left[ch].pop(); right[ch].pop();

            q.push({a,b});
        }
    }
    // case 2: a--?

    for(int i=0; i<26; i++){
        ch = 'a'+i;
        stop = min( left[ch].size() , right['?'].size() );
        
        for(int j=0; j<stop; j++){
            a = left[ch].front();
            b = right['?'].front();

            left[ch].pop(); right['?'].pop();

            q.push({a,b});
        }
    }

    for(int i=0; i<26; i++){
        ch = 'a'+i;
        stop = min( left['?'].size() , right[ch].size() );
        
        for(int j=0; j<stop; j++){
            a = left['?'].front();
            b = right[ch].front();

            left['?'].pop(); right[ch].pop();

            q.push({a,b});
        }
    }
    // case 3: ?--?
    stop = min( left['?'].size() , right['?'].size() );
        
    for(int j=0; j<stop; j++){
        a = left['?'].front();
        b = right['?'].front();

        left['?'].pop(); right['?'].pop();

        q.push({a,b});
    }

    n = q.size();

    cout<<n<<"\n";

    n=q.size();
    for(int i=0; i<n; i++){
        a = q.front().first;
        b = q.front().second;

        q.pop();
        cout<<a<<" "<<b<<"\n";
    }

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/