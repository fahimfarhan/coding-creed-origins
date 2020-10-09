class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1){  return false; }
        int kount = 0;
        int m = 1;
        for(int i=0; i<32; i++) {
            m = 1 << i;
            if( (m&n) == m) {   kount++;    }
        }
        
        return (kount == 1);
    }
    

};