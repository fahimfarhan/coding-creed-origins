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

    string input, s;
    int len, row, col;
    // cin>>input;
    getline(cin,input);

    len = input.size();

    s = "";
    for(int i=0; i<len; i++){ if(input[i]!=' '){    s = s + input[i]; }  }

    len = s.size();

    double d = sqrt(len);

    row = floor(d);
    col = ceil(d);

    char **a;
    a = new char*[row+1];
    for(int i=0; i<=row;i++){   a[i] = new char[col+1]; }

    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            a[i][j] = '\0';
        }
    }

    int k = 0;
    bool b = true;

    for(int i=0; i<row; i++){
        if(!b){ break; }  
        for(int j=0; j<col; j++){
            a[i][j] = s[k];
            k++;
            if(k == len){  b = false;  break; }
        }
    }

    for(int i=0; i<col; i++){
        string w="";
        for(int j=0; j<row; j++){
            //if(a[i][j] == '\0'){    continue; }
            //else
            {   w = w + a[j][i];    }
        }

        cout<<w<<" ";
    }cout<<"\n";

    for(int i=0; i<=row;i++){   delete[] a[i];  }
    delete[] a;


    return 0;
}
