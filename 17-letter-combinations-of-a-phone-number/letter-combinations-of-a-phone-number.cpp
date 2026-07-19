class Solution {
public:
    vector<string> mapping = {
        "",     "",     "abc",  "def",
        "ghi",  "jkl",  "mno",
        "pqrs", "tuv",  "wxyz"
    };
    
    void solve(int index, string digits,
               string current,
               vector<string>& result) {
        
        // Base case
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        
        for (char ch : letters) {
            solve(index + 1, digits,
                  current + ch, result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        
        if (digits.empty())
            return result;
        
        solve(0, digits, "", result);
        
        return result;
    }
};
