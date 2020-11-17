#include <bits/stdc++.h>

using namespace std;

#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2

vector<int> segmentTree;

void initSegmentTree(int N) {
  // the required segment tree array length is 2*2^ ( floor(log2(N)) + 1 )
  int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
  segmentTree.resize(length, 0);
}

void buildSegmentTree(int code, int A[], int node, int b, int e) {
  if(b == e) {  // we are at a leaf
    if( code == RANGE_SUM ) {
      segmentTree[node] = A[b];  // for sum, store value
    } else{
      segmentTree[node] = b; // for min/max store index
    }
  }else{
    int leftIndex = node << 1;
    int rightIndex = leftIndex | 1;
    int mid = (b + e) / 2;

    buildSegmentTree(code, A, leftIndex, b, mid);
    buildSegmentTree(code, A, rightIndex, (mid+1), e);
    
    int leftContent = segmentTree[leftIndex];
    int rightContent = segmentTree[rightIndex];

    if(code == RANGE_SUM) {
      segmentTree[node] = leftContent + rightContent;
    }else{
      int leftValue = A[leftContent];
      int rightValue = A[rightContent];

      if(code == RANGE_MIN) {
        segmentTree[node] = (leftValue <= rightValue) ? leftContent : rightContent;
      }else{
        segmentTree[node] = (leftValue >= rightValue) ? leftContent : rightContent;
      }
    }
  }
}


int query(int code, int A[], int node , int b, int e, int i, int j) {
  if(i > e || j < b) return -1;
  if(b >= i && e <= j) return segmentTree[node];

  int mid = (e + b) / 2;
  int leftNode = node << 1;
  int rightNode = leftNode | 1;

  int p1 = query(code, A, leftNode, b, mid , i, j );
  int p2 = query(code, A, rightNode, (mid+1), e, i, j);

  if(p1 == -1) {  return p2;  } // can happen if the query is outside the range
  if(p2 == -1) {  return p1;  } // same as above

  if(code == RANGE_SUM) { return (p1+p2);  }
  else if(code == RANGE_MIN) { return ( (A[p1]<=A[p2]) ? p1:p2); }
  else{ return ( (A[p1]>=A[p2]) ? p1:p2); }
}


int main() {
  int arra[] = {8,7,3,9,5,1,10};
  initSegmentTree(7);
  buildSegmentTree(RANGE_MIN, arra, 1, 0, 6);
  cout<<query(RANGE_MIN, arra, 1, 0, 6, 1, 3)<<"\n";
  return 0;
}
