#include <bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main()
{
int t;
cin >> t;

while(t--)
{
    int n;
    cin >> n;

    vector <int> v1,v2;
    int x;
    map <int,int> m;

    for(int i=0;i<n;i++)
    {
        cin >> x;

        m[x]++;
        v1.push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        cin >> x;

        m[x]--;
        v2.push_back(x);
    }

    bool flag = false;
    v1.clear();
    v2.clear();

    int mi = x;

    for(auto i:m)
    {
        mi = min(mi, i.first);
        x = abs(i.second);

        if(x%2)
            flag = true;

        x = i.second;

        if(x > 0)
        {
            x /= 2;

            while(x--)
                v1.push_back(i.first);
        }
        else if(x < 0)
        {
            x = abs(x)/2;

            while(x--)
                v2.push_back(i.first);
        }
    }

    if(flag)
    {
        cout << -1 << endl;
        continue;
    }

    reverse(v2.begin(),v2.end());

    int ans = 0;

    for(int i=0;i<v1.size();i++)
        ans += min(2*mi,min(v1[i],v2[i]));

    cout << ans << endl;
}
    return 0;
} 