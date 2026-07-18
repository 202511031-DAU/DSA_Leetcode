class Solution {
public:
    void solve(int start, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& result) {
        
        // Add current subset
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;
            
            // Choose
            current.push_back(nums[i]);
            
            // Move forward
            solve(i + 1, nums, current, result);
            
            // Backtrack
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> current;
        
        solve(0, nums, current, result);
        
        return result;
    }
};
