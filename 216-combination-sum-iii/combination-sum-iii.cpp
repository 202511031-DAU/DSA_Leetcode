class Solution {
public:
    void solve(int start, int k, int target,
               vector<int>& current,
               vector<vector<int>>& result) {
        
        // Valid combination
        if (k == 0 && target == 0) {
            result.push_back(current);
            return;
        }
        
        // Invalid case
        if (k == 0 || target < 0)
            return;
        
        for (int i = start; i <= 9; i++) {
            
            // Choose number
            current.push_back(i);
            
            // Move forward (no reuse)
            solve(i + 1, k - 1, target - i,
                  current, result);
            
            // Backtrack
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        
        solve(1, k, n, current, result);
        
        return result;
    }
};
