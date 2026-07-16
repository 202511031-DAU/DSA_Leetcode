class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int lastSmaller = nums[0];
        int cnt = 1;
        int longest = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == lastSmaller + 1) {
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller) {
                // duplicate → ignore
                continue;
            }
            else {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
