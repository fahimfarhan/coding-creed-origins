class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeroKount = 0, oneKount = 0, minimus = 0, maximus = 0;    
    
        for(int n : nums) {
            if( (n&1) == 1) {  oneKount++; }
            else{   zeroKount++;    }
        }
        
        minimus = min(zeroKount, oneKount);
        maximus = minimus << 1; // x2
        
        return maximus;
    }
};