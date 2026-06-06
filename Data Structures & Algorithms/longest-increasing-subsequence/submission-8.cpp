class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i,int p,vector<int>& nums)
    {
        int n=nums.size();
        if(i>=n)
            return 0;
        if(dp[i][p+1]!=-1)
            return dp[i][p+1];
        int res1=helper(i+1,p,nums);
        if(p==-1 || nums[i]>nums[p])
        {
            res1=max(res1,1+helper(i+1,i,nums));
        }
        return dp[i][p+1]=res1;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(0,-1,nums);
    }
};
