#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
        
    int T;
    string *s;

    cin>>T;
    while(T--) {
        int mp[256] = {0};
        int K;
        cin>>K;

        int price;
        char ch;
        for(int i=0; i<K; i++) {
            cin>>ch>>price;
            mp[(int)ch] = price;
        }

        int M;
        cin>>M;
        s = new string[M+1];    
        for(int i=0; i<=M; i++) {
            getline(cin,s[i]);
        }

        double kost = 0;
        for(int i=1; i<=M; i++) {
            // cerr<<s[i]<<"\n";
            for(int j=0; j<s[i].size(); j++) {
                // cerr<<s[i][j]<<"";
                int index = s[i][j];
                kost += mp[index];
            }
        }
        kost = kost / 100;
        cout<<kost<<"$\n";
        delete[] s;
    }

    return 0;
}