#include <bits/stdc++.h>

using namespace std;

int main() {

    int T, N , price, M;
    char ch;
    string s;

    cin>>T;
    while(T--) {
        int mp[256] = {0};
        cin>>N;
        for(int i=0; i<N; i++) {
            cin>>ch>>price;
            mp[ch] = price;
        }

        price = 0;
        cin>>M;
        for(int i=0; i<=M; i++) { // cz the cursor is in the above line. So 1st getLine reads s = "". That's why we missed the last line! Making i<=M should solve it!
            getline(cin, s);
            for(int j=0; j<s.size(); j++) {
                price += mp[s[j]];
            } 
        }

        float dollar = price*1.0/100;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout<<dollar<<"$\n";
    }

    return 0;
}