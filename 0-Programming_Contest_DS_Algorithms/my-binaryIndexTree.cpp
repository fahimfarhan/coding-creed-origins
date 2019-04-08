#include <bits/stdc++.h>

using namespace std;


int *BITree;
int a[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    
int n;

int getSum(int index){
    int sum = 0; 
    index = index+1;

    while(index>0){
        sum = sum+BITree[index];
        index = index - (index & (-index));
    }
    return sum;
}

void updateBITree(int index, int value){
    index = index+1;
    while(index<=n){
        BITree[index]+=value;
        index = index + (index & (-index) );
    }
}

void constructBITree(){
    BITree = new int[n+1];
    for(int i=0; i<n; i++){    BITree[i] = 0;  }
    for(int i=0; i<n; i++)
    {   updateBITree(i, a[i]); }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    n = sizeof(a)/sizeof(a[0]); 

    constructBITree();

        cout << "Sum of elements in arr[0..5] is "
        << getSum(5); 
  
    // Let use test the update operation 
    a[3] += 6; 
    updateBITree(3, 6); //Update BIT for above change in arr[] 
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum( 5); 
  
    return 0;
}