class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);  // dp[i] = length of LIS ending at i

        for (int i = 1; i < n; i++) {
            int maxLen = 0; // reset for each i
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxLen = max(maxLen, dp[j]);
                }
            }
            dp[i] = maxLen + 1;
        }

        int largest = INT_MIN;
        for (int num : dp) {
            if (num > largest) {
                largest = num;
            }
        }

        return largest;
    }
};