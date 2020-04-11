#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    
    while(true){
        while(i<n && nums[i]!=0){  i++;   } // so a[i] = 0 after the loop
        while(j<n && nums[j]==0){  j++;   } // so a[j] !=0 after the loop
        if(i<n && j<n && i<j){
            if( (nums[j]!=0) && (nums[i] == 0) ){
                nums[i] = nums[j];
                nums[j] = 0;
            }
        }else{
            break; 
        }
    }
}

int main(){
    vector<int> v = {0,1,0,3,12};
    vector<int> v1 = {1,0};
    vector<int> v2 = {1,2};
    moveZeroes(v);
    for(int x: v){
        cout<<x<<" ";
    }
    return 0;
}