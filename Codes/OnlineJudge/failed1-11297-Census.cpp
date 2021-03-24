#include <bits/stdc++.h>

using namespace std;

#define node pair<int, int>
#define x first
#define y second

const int maxn = 1010;

int a[maxn][maxn];
int treeMinimus[maxn*4][maxn*4], treeMaximus[maxn*4][maxn*4];

bool operator == (const node& leftNode, const node& rightNode) {
  return ((leftNode.x == rightNode.x) && (leftNode.y == rightNode.y));
}

inline bool isInside(node topLeft, node bottomRight, node u) {
  return ( (topLeft.x <= u.x) && (u.x <= bottomRight.x) 
  && (topLeft.y <= u.y) && (u.y <= bottomRight.y));
}

inline void build(node si, node ss, node se) {
  if(ss == se) {
    treeMinimus[si.x][si.y] = a[ss.x][ss.y];
    treeMaximus[si.x][si.y] = a[ss.x][ss.y];
    return;
  }

  node mid = { ((ss.x + se.x) >> 1), ((ss.y + se.y) >> 1)};
  node siMid = {(si.x << 1), (si.y << 1) };
  
  build(siMid, ss, mid);
  treeMinimus[si.x][si.y] = treeMinimus[siMid.x][siMid.y];
  treeMaximus[si.x][si.y] = treeMaximus[siMid.x][siMid.y];

  // ss.x != se.x && ss.y != se.y
  if(ss.x != se.x && ss.y != se.y) {
    node si1 = {siMid.x+1, siMid.y+1};
    node ss1 = {mid.x+1, mid.y+1};
    // node se1 = se;
    build(si1, ss1, se);
    treeMinimus[si.x][si.y] = min(treeMinimus[si.x][si.y], treeMinimus[si1.x][si1.y]);
    treeMaximus[si.x][si.y] = max(treeMaximus[si.x][si.y], treeMaximus[si1.x][si1.y]);
  }
  if(ss.x!=se.x) {
    node si1 = {siMid.x+1, siMid.y};
    node ss1 = {mid.x+1, ss.y};
    node se1 = {se.x, mid.y};

    build(si1, ss1, se1);
    treeMinimus[si.x][si.y] = min(treeMinimus[si.x][si.y], treeMinimus[si1.x][si1.y]);
    treeMaximus[si.x][si.y] = max(treeMaximus[si.x][si.y], treeMaximus[si1.x][si1.y]); 
  }
  if(ss.y != se.y) {
    node si1 = { siMid.x , siMid.y+1 };
    node ss1 = {ss.x, mid.y+1};
    node se1 = {mid.x, se.y};

    build(si1, ss1, se1);
    treeMinimus[si.x][si.y] = min(treeMinimus[si.x][si.y], treeMinimus[si1.x][si1.y]);
    treeMaximus[si.x][si.y] = max(treeMaximus[si.x][si.y], treeMaximus[si1.x][si1.y]);  
  }
}

inline void update(node si, node ss, node se, node u, int value) {
  if(ss == se) {
    treeMinimus[si.x][si.y] = value;
    treeMaximus[si.x][si.y] = value;
    return;
  }

  node mid = { ((ss.x + se.x) >> 1), ((ss.y+se.y)>>1) };

  if(isInside(ss, mid, u)) {
    node si1 = {(si.x << 1), (si.y << 1) };
    update(si1, ss, mid, u, value);
  }

  node ss1 = { (mid.x+1), (mid.y+1) };
  if(isInside(ss1, se, u)) {
    node si1 = {(si.x << 1) + 1, (si.y << 1)+1 };
    update(si1, ss1, se, u, value);
  }

  ss1.x = mid.x+1;
  ss1.y = ss.y;

  node se1 = {se.x, mid.y};

  if(isInside(ss1, se1, u)) {
    node si1 = {(si.x << 1) + 1, (si.y << 1)};
    update(si1, ss1, se1, u, value);
  }

  ss1.x = ss.x;
  ss1.y = mid.y+1;

  se1.x = mid.x;
  se1.y = se.y;

  if(isInside(ss1, se1, u)) {
    node si1 = {si.x << 1, (si.y<<1) + 1 };
    update(si1, ss1, se1, u, value);
  }
}

inline pair<int,int> query(node si, node ss, node se, node topLeft, node bottomRight) {
  if( (ss.x <= topLeft.x) && (bottomRight.x <= se.x) &&
    (ss.y <= topLeft.y) && (bottomRight.y <= se.y)
  ){
    // completely inside
    return { treeMinimus[si.x][si.y], treeMaximus[si.x][si.y]  };
  } 

  node mid = {((ss.x+se.x)>>1), ((ss.y+se.y)>>1)};
  node si1 = {(si.x<<1), (si.y<<1)};

  // first 
  node first = query(si1, ss, mid, topLeft, bottomRight);
  
  node second = {0,0}, third = {0,0}, forth = {0,0};
  // second
  if((ss.x != se.x) && (ss.y!=se.y)) {
    si1 = {(si.x<<1)+1, (si.y<<1)+1};
    node ss1 = {mid.x+1, mid.y+1};
    second = query(si1, ss1, se, topLeft, bottomRight);
  }

  if(ss.x != se.x) {
    si1 = {(si.x<<1)+1, (si.y<<1)};
    node ss1 = {ss.x, mid.y+1};
    node se1 = {mid.x, se.y};
    third = query(si1, ss1, se1, topLeft, bottomRight);
  }

  if(ss.y != se.y) {
    si1 = {(si.x<<1), (si.y<<1)+1};
    node ss1 = {mid.x + 1, ss.y};
    node se1 = {se.x, mid.y};
    
    forth = query(si1, ss1, se1, topLeft, bottomRight);
  }

  node ret = {(first.x+second.x+third.x+forth.x), (first.y+second.y+third.y+forth.y)};
  return ret;
}

inline void test() {
node a;
  a.x = 12;
  a.y = 1;

  node b = {1,1};

  cout<<(a == b)<<"\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q, x1, y1, x2, y2, v;
  char ch;
  cin>>n;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>a[i][j];
    }
  }

  build({1,1}, {1,1}, {n,n});

  cin>>q;
  while(q--) {
    cin>>ch;
    if(ch == 'c') {
      cerr<<"ch == c\n";
      cin>>x1>>y1>>v;
      update({1,1}, {1,1}, {n,n}, {x1,y1}, v);
    }else if(ch == 'q') {
      cerr<<"ch == q\n";
      cin>>x1>>y1>>x2>>y2;
      node res = query({1,1}, {1,1}, {n,n},{x1, y1}, {x2, y2});
      cout<<res.first<<" "<<res.second<<"\n";
    } else{
      cerr<<"ch =="<<ch<<" sth else\n";
      
    }
  }

  return 0;
}