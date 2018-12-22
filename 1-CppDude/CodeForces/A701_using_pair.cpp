#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    pair<int, int> p[101];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    for (int i = 0; i < n / 2; i++)
        cout << p[i].second + 1 << " " << p[n - i - 1].second + 1 << endl;
    return 0;
}