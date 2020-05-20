class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int answer = 0;
        int pref = 0;

        unordered_map<int,int> countPref;

        countPref[pref]++;

        for(int R=0; R<n; R++) {
            pref += nums[R];
            int need = pref - k;
            answer += countPref[need];
            countPref[pref]++;
        }

        return answer;
    }
};