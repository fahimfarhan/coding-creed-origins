#include <bits/stdc++.h>

#define MAX 1000

int tree[MAX] = {0};
int lazy[MAX] = {0};

/*
si -> indexOfCurrentNodeInSegmentTree;
ss -> startingIndexOfElementsThatCurrentNodeStoresSum
se -> endingIndexOfElementsThatCurrentNodeStoresSum
us -> startingIndexIfUpdateQuery
ue -> endingIndexIfUpdateQuery
diff -> which we need to add in the range us to ue
*/

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
    /*
    if lazy value[si] != 0 for current node of segment tree,
    then there are some pending updates. So make sure the pending updates
    are done before making new updates. cz this value may be used py parent 
    after recursive calls( see last line of this function)
    */
    
    if(lazy[si] != 0) {
        // make pending updates using value stored in lazy nodes
        tree[si] += (se - ss + 1) * lazy[si];

        // check if this is a leaf node. cz if it is a leaf node, we cannot go further
        if(ss != se) {
            lazy[ (si<<1) + 1 ] += lazy[si];
            lazy[ (si<<1) + 2 ] += lazy[si];
        }

        // set the lazy value for current node = 0 since we have just updated it
        lazy[si] = 0;
    }

    // out of range 
    if( (ss > se) || (ss > ue) || (se < us) ) {
        return;
    }

    // current segnet is fully in range
    if( (ss >= us) && (se <= ue) ){
         // Add the difference to current node 
        tree[si] += (se - ss +1)*diff;
        // check if leaf node or not  
        if( ss != se ) {
            // this is where we store values in lazy nodes
            // instwead of updating the entire segment tree
            // because we dont need these updated value right now
            // therefore we postpone updates by storing values in lazy[]
            lazy[(si<<1) + 1] += diff;
            lazy[(si<<1) + 2] += diff;
            
        }  
        return;
    }

    // else if not completely in range, but overlaps, recur for the children
    int mid = ss + se;
    mid = mid >> 1;

    updateRangeUtil( ( (si<<1)+1), ss, mid, us,ue,diff);
    updateRangeUtil( ( (si<<1)+2), mid, se, us,ue,diff);
    
    // use the resulting children to update current node
    tree[si] = tree[ (si << 1) + 1 ] + tree[ (si << 1) + 2 ];

}


// Function to update a range of values in segment 
// tree 
/*  us and eu -> starting and ending indexes of update query 
    ue  -> ending index of update query 
    diff -> which we need to add in the range us to ue */

void updateRange(int n, int us, int ue, int diff) {
    updateRangeUtil(0,0,n-1,us,ue,diff);
}

  
/*  A recursive function to get the sum of values in given 
    range of the array. The following are parameters for 
    this function. 
    si --> Index of current node in the segment tree. 
           Initially 0 is passed as root is always at' 
           index 0 
    ss & se  --> Starting and ending indexes of the 
                 segment represented by current node, 
                 i.e., tree[si] 
    qs & qe  --> Starting and ending indexes of query 
                 range */

int getSumUtil(int ss, int se, int qs, int qe, int si) {
    // if lazy flag is set for current node of the segment tree,
    // then there are some pending updates. So we need to make sure 
    // the pendings updates are done before processing the sub sum query
    if(lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];

        // leaf check
        if(ss != se) {
            lazy[si<<1 + 1] += lazy[si];
            lazy[si<<1 + 2] += lazy[si];
        }
        // unset the current node
        lazy[si] = 0;
    }

    // out of range 
    if(ss > se || ss > qe || se < qs) {
        return 0;
    }

    // if the segment lies within range
    if(ss >= qs && se<= qe) {
        return tree[si];        
    }

    int mid = ss + se;
    mid = mid >> 1;
    return getSumUtil(ss, mid, qs, qe, ((si<<1) + 1) ) + 
           getSumUtil((mid+1), se, qs, qe, ((si<<1) + 2) );
}



// Return sum of elements in range from index qs (query 
// start) to qe (query end).  It mainly uses getSumUtil() 

int getSum(int n, int qs, int qe) {
    // check for input error
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(0, n-1, qs, qe, 0); 
}

  
// A recursive function that constructs Segment Tree for 
//  array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtil(int arr[], int ss, int se, int si) 
{ 
    // out of range as ss can never be greater than se 
    if (ss > se) 
        return ; 
  
    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (ss == se) 
    { 
        tree[si] = arr[ss]; 
        return; 
    } 
  
    // If there are more than one elements, then recur 
    // for left and right subtrees and store the sum 
    // of values in this node 
    int mid = (ss + se)/2; 
    constructSTUtil(arr, ss, mid, si*2+1); 
    constructSTUtil(arr, mid+1, se, si*2+2); 
  
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree and 
   calls constructSTUtil() to fill the allocated memory */
void constructST(int arr[], int n) 
{ 
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, 0); 
} 

int main() {

    int a[] = {1,3,5,7,9,11};
    int n = 6;

    constructST(a,n);

    // Print sum of values in array from index 1 to 3 
    printf("Sum of values in given range = %d\n", 
           getSum(n, 1, 3)); 
  
    // Add 10 to all nodes at indexes from 1 to 5. 
    updateRange(n, 1, 5, 10); 
  
    // Find sum after the value is updated 
    printf("Updated sum of values in given range = %d\n", 
            getSum( n, 1, 3)); 
  
    return 0; 
}