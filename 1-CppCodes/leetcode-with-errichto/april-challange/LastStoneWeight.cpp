#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    priority_queue<int> heap;
public:
    int lastStoneWeight(vector<int>& stones) {
        int dw = 0, x=0,y=0;
        
        for(int stone : stones) {   heap.push(stone);   }

        while(heap.size() >= 2) {
            y = heap.top(); heap.pop();
            x = heap.top(); heap.pop();
            dw = y-x;
            heap.push(dw);
        }
        return heap.top();
    }
};

int main() {

    vector<int> v = {2,7,4,1,8,1};
    Solution s;
    int dw = s.lastStoneWeight(v);
    cout<<dw<<"\n";
    return 0;
}