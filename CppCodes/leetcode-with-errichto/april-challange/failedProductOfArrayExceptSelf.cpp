class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n = 1;
        for(int i=1; i<nums.size(); i++) {      n = n * nums[i];    }
        
        int j = 0;
        output.push_back(n);
        for(int i = 1; i<nums.size(); i++) {
            j = i - 1;
            n = n/nums[i];
            n = n * nums[j];
            
            output.push_back(n);
        }
        
        return output;
    }
};