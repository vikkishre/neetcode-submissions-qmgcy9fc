#include <cstring>
class Solution {
public:
    // Memoization table to prevent Time Limit Exceeded (TLE)
    // 201 (max array size) x 10001 (max possible target sum)
    int memo[201][10001];

    bool helper(vector<int>& nums, int target, int index) {
        // Base Case 1: Target reached
        if (target == 0) return true;
        
        // Base Case 2: Out of bounds or target impossible
        if (index < 0 || target < 0) return false;

        // Base Case 3: Return cached result if already calculated
        if (memo[index][target] != -1) return memo[index][target];

        bool notTake = helper(nums, target, index - 1);
        bool take = false; // Initialize to false to avoid junk values

        // Only try to "take" if the current number fits in the remaining target
        if (nums[index] <= target) {
            take = helper(nums, target - nums[index], index - 1);
        }

        // Store result in memo table and return
        return memo[index][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // If total sum is odd, it's impossible to split into two equal integers
        if (sum % 2 != 0) return false;

        // Initialize memo table with -1 (meaning "not yet calculated")
        memset(memo, -1, sizeof(memo));

        return helper(nums, sum / 2, nums.size() - 1);
    }
};
