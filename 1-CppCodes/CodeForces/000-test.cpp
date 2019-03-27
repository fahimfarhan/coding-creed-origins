#include <cstdio>

int p[200010], used[200010];
int main()
{
    int n; scanf("%d", &n);
    int mini=0;
    for(int i=0; i<n-1; ++i) {
        int q; scanf("%d", &q);
        p[i+1]=p[i]+q;
        if (p[i+1]<p[mini]) mini=i+1;
    }
    int x=1-p[mini];
    for(int i=0; i<n; ++i) {
        p[i]+=x;
        if (p[i]<1 or p[i]>n or used[p[i]]++) { puts("-1"); return 0; }
    }
    for(int i=0; i<n; ++i) printf("%d ", p[i]);
    puts("");
}