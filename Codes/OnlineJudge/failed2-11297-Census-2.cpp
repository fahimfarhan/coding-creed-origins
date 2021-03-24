#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int a[maxn][maxn];
int tree[maxn*4][maxn*4], f[maxn*4][maxn*4];

void build(int six, int siy, int ssx, int ssy, int sex, int sey) {
  if((ssx == sex) && (ssy == sey)) {
    tree[six][siy] = a[ssx][ssy];
    f[six][siy] = a[ssx][ssy];
    return;
  }

  int midx =ssx + (sex-ssx)>>1;
  int midy = ssy + (sey - ssy)>>1;

  int leftx = six << 1;
  int lefty = siy << 1;

  int rightx = leftx | 1;
  int righty = lefty | 1;

  build(leftx, lefty, ssx, ssy, midx, midy);
  tree[six][siy] = tree[leftx][lefty];
  f[six][siy] = f[leftx][lefty]; 

  if(ssx != sex && ssy != sey) {
    build(rightx, righty, midx+1, midy+1, sex, sey);
    tree[six][siy] = max(tree[six][siy], tree[rightx][righty]);
    f[six][siy] = min(f[six][siy], f[rightx][righty]); 
  }
  if(ssy != sey) {
    build(leftx, righty, midx+1, midy+1, sex, sey);
    tree[six][siy] = max(tree[six][siy], tree[rightx][righty]);
    f[six][siy] = min(f[six][siy], f[rightx][righty]);
  }

}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  return 0;
}