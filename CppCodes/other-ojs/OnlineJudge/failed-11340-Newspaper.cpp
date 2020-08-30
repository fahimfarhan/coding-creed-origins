#include <bits/stdc++.h>
#include <string>

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
            mp[(int)ch] = price;
        }

        price = 0;
        cin>>M;
        for(int i=0; i<M; i++) {
            getline(cin, s);
            for(int j=0; j<s.size(); j++) {
                int index = s[j];
                price += mp[index];
            }
        }
        float dollar = price*1.0/100;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout<<dollar<<"$\n";
    }

    return 0;
}