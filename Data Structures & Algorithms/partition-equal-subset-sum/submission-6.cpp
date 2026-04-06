class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        // If sum is odd, we cannot partition it into two equal integers
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        // dp[i] will be true if a sum of i is possible
        vector<bool> dp(target + 1, false);
        
        // Base case: a sum of 0 is always possible (by picking no elements)
        dp[0] = true;

        for (int num : nums) {
            // Iterate backwards to ensure each number is only used once
            // and we don't overwrite values needed for the current iteration
            for (int i = target; i >= num; i--) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
            // Optimization: if we already found the target, we can exit early
            if (dp[target]) return true;
        }

        return dp[target];
    }
};
