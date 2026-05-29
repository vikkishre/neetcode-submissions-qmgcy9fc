class Solution {
public:
    vector<int> dp;
    int helper(int i,vector<int> & nums)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int res1=nums[i]+helper(i+2,nums);
        int res2=helper(i+1,nums);
        return dp[i]=max(res1,res2);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return helper(0,nums);
    }
};
