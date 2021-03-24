#include <bits/stdc++.h>
using namespace std;

#define maxn 1010
int a[maxn][maxn];
int minTree[maxn*4][maxn*4];
int maxTree[maxn*4][maxn*4];

#define node pair<int, int>
#define x first
#define y second

#define MINIMUS first
#define MAXIMUS second

#define MIN(q,w,e,r) min(min(q,w), min(e,r))
#define MAX(q,w,e,r) max(max(q,w), max(e,r))

#define minT(someNode) minTree[someNode.x][someNode.y]
#define maxT(someNode) maxTree[someNode.x][someNode.y]

inline void build(node si, node ss, node se) {
  if((ss.x == se.x) && (ss.y == se.y)) {
    minTree[si.x][si.y] = a[ss.x][ss.y];
    maxTree[si.x][si.y] = a[ss.x][ss.y];
    return;
  }

  node mid = { ((ss.x+se.x)>>1), ((ss.y+se.y)>>1)  };
  // first
  {
    node si1 = { (si.x<<1), (si.y<<1) };

    build(si1, ss, mid);
    minT(si) = minT(si1);
    maxT(si) = maxT(si1);
  }
  
  // 2
  if(ss.y != se.y) {
    node si2 = { (si.x<<1), ((si.y<<1)+1) };
    node ss2 = {ss.x, (mid.y+1)};
    node se2 = {mid.x, se.y};

    build(si2, ss2, se2);
    minT(si) = min(minT(si), minT(si2) ) ;
    maxT(si) = max(maxT(si), maxT(si2) ) ;
  }

  // 3
  if((ss.x!=se.x) && (ss.y!=se.y)) {  
    node si3 =  { ((si.x<<1) + 1), ((si.y<<1)+1) };
    node ss3 = { (mid.x+1), (mid.y+1)};
  
    build(si3, ss3, se);
    minT(si) = min(minT(si), minT(si3) ) ;
    maxT(si) = max(maxT(si), maxT(si3) ) ;
  }

  // 4
  if(ss.x!=se.x) {  
    node si4 =  { ((si.x<<1) + 1), ((si.y<<1)) };
    node ss4 = { (mid.x+1), ss.y};
    node se4 = {se.x, mid.y };
  
    build(si4, ss4, se4);
    minT(si) = min(minT(si), minT(si4) ) ;
    maxT(si) = max(maxT(si), maxT(si4) ) ;
  }
}

inline void update(node si, node ss, node se, node u, int value) {
  if((ss.x == se.x) && (ss.y == se.y)) {
    minTree[si.x][si.y] = value;  // a[ss.x][ss.y];
    maxTree[si.x][si.y] = value;  // a[ss.x][ss.y];
    return;
  }
  node mid = { ((ss.x+se.x)>>1), ((ss.y+se.y)>>1)  };

  if((ss.x <= u.x) && (u.x <= mid.x) && (ss.y <= u.y) && (u.y <= mid.y) ) {
    node si1 = { (si.x<<1), (si.y<<1) };
    update(si1, ss, mid, u, value);

    minT(si) = min(minT(si), minT(si1) ) ;
    maxT(si) = max(maxT(si), maxT(si1) ) ;

  }
  
  if((ss.x <= u.x) && (u.x <= mid.x) && (mid.y+1 <= u.y) && (u.y <= se.y) ) {
    node si2 = { (si.x<<1), ((si.y<<1)+1) };
    node ss2 = {ss.x, (mid.y+1)};
    node se2 = {mid.x, se.y};

    update(si2, ss2, se2, u, value);

    minT(si) = min(minT(si), minT(si2) ) ;
    maxT(si) = max(maxT(si), maxT(si2) ) ;
  
  }
  if( (mid.x+1<=u.x) && (u.x <= se.x) && (mid.y+1 <= u.y)&&(u.y<=se.y) ) {
    node si3 =  { ((si.x<<1) + 1), ((si.y<<1)+1) };
    node ss3 = { (mid.x+1), (mid.y+1)};

    update(si3, ss3, se, u, value);

    minT(si) = min(minT(si), minT(si3) ) ;
    maxT(si) = max(maxT(si), maxT(si3) ) ;

  }
  if( (mid.x+1<=u.x) && (u.x <= se.x) && (ss.y <= u.y) && (u.y <= mid.y) ) {
    node si4 =  { ((si.x<<1) + 1), ((si.y<<1)) };
    node ss4 = { (mid.x+1), ss.y};
    node se4 = {se.x, mid.y };

    update(si4, ss4, se4, u, value);

    minT(si) = min(minT(si), minT(si4) ) ;
    maxT(si) = max(maxT(si), maxT(si4) ) ;
  }
}


inline void printer(string s, node p) {
  cerr<<s<<" "<<p.second<<" "<<p.first<<"\n";
}


inline node query(node si, node ss, node se, node qs, node qe) {
  if( (qe.x < ss.x) || (se.y < qs.y) || (ss.x < qs.x) || (qe.y < ss.y) ) {
    // cerr<<" case 1\n";
    node completelyOutSide = {0,0};
    completelyOutSide.MINIMUS = INT_MAX;
    completelyOutSide.MAXIMUS = INT_MIN;

    return completelyOutSide;
  }

  // case 2: completely inside
  // if( (ss.x <= qs.x) && (qe.x <= se.x) && (ss.y <= qs.y) && (qe.y <= se.y) ) {
  if( (qs.x <= ss.x) && (se.x <= qe.x) && (qs.y <= ss.y) && (se.y <= qe.y) ) { 
    // todo: debug here sth is wrong
    // cerr<<" case 2\n";
    node result;
    result.MINIMUS = minT(si);
    result.MAXIMUS = maxT(si);
    // printer("case2", result);
    return result;
  }

  node mid = { ((ss.x+se.x)>>1), ((ss.y+se.y)>>1)  };
  node first = {INT_MAX,INT_MIN}, second = {INT_MAX,INT_MIN}, 
  third = {INT_MAX,INT_MIN}, forth = {INT_MAX,INT_MIN};

  // first
  // if( (mid.x <= qe.x) && (mid.y <= qe.y)) 
  {
   node si1 = { (si.x<<1), (si.y<<1) };
   first = query(si1, ss, mid, qs, qe);
  }

  if(ss.y != se.y)
  {
    // if( (qs.x <= mid.x) && (mid.y < qe.y) )
    {
      node si2 = { (si.x<<1), ((si.y<<1)+1) };
      node ss2 = {ss.x, (mid.y+1)};
      node se2 = {mid.x, se.y};
      second = query(si2, ss2, se2, qs, qe);
    }
  }

  if((ss.x!=se.x) && (ss.y!=se.y)){
    // if((mid.x < qe.x) && (mid.y < qe.y)) 
    {
      node si3 =  { ((si.x<<1) + 1), ((si.y<<1)+1) };
      node ss3 = { (mid.x+1), (mid.y+1)};
      
      third = query(si3, ss3, se, qs, qe);
    }
  }

  if(ss.x!=se.x) {
    // if( qs.x <= mid.x && mid.y < qe.y ) 
    {
      node si4 =  { ((si.x<<1) + 1), ((si.y<<1)) };
      node ss4 = { (mid.x+1), ss.y};
      node se4 = {se.x, mid.y };

      forth = query(si4, ss4, se4, qs, qe);
    }
  }

  node result = {0,0};

  // printer("first", first);
  // printer("second", second);
  // printer("third", third);
  // printer("forth", forth);

  result.MINIMUS = MIN(first.MINIMUS, second.MINIMUS, third.MINIMUS, forth.MINIMUS);
  result.MAXIMUS = MAX(first.MAXIMUS, second.MAXIMUS, third.MAXIMUS, forth.MAXIMUS);

  return result;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, Q;
  
  cin>>N;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin>>a[i][j];
    }
  }

  node si = {1,1};
  node ss = {1,1};
  node se = {N,N};

  build(si, ss, se);

  cin>>Q;
  char ch;
  int x1, y1, x2, y2, v;

  while(Q--) {
    cin>>ch;
    if(ch == 'q') {
      cin>>x1>>y1>>x2>>y2;
      // if(x2<x1) { swap(x1, x2); }
      // if(y2<y1) { swap(y1, y2); }

      // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
      node result = query({1,1}, {1,1}, {N,N}, {x1, y1}, {x2, y2});
      cout<<result.MAXIMUS<<" "<<result.MINIMUS<<"\n";
    }else if(ch == 'c') {
      cin>>x1>>y1>>v;
      // cout<<x1<<" "<<y1<<" "<<v<<"\n";
      update({1,1}, {1,1}, {N,N}, {x1, y1}, v);
    }
  }

  return 0;
}