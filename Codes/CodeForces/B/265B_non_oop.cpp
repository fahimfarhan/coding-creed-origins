#include <bits/stdc++.h>
using namespace std;
#define EAT 1
#define JUMP 1

int main()
{
    int n, ans, *A;

    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ans = A[0] + EAT;
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
        {
            ans = ans + JUMP + A[i] - A[i - 1] + EAT;
        }
        else
        {
            ans = ans + A[i - 1] - A[i] + JUMP + EAT;
        }
    }
    cout << ans << endl;

    if (!A) delete[] A;

    return 0;
}