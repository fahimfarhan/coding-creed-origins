#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, n;
    string s;

    cin>>T;
    while(T--){
        cin>>s;
        n = 0;
        for(int i=s.size() - 1; i>=0; i--){
            n = n*10 + s[i] - '0';
        }
        cout<<n<<"\n";
    }

    return 0;
}