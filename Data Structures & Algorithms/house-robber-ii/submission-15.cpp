class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> dp(nums.size()+1,-1);
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        for(int i=3;i<=nums.size()-1;i++)
        {
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        int res=dp[nums.size()-1];
        dp.clear();
        dp.resize(nums.size()+1,-1);
        dp[2]=nums[1];
        dp[3]=max(nums[1],nums[2]);
        for(int i=4;i<=nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        return max(res,dp[nums.size()]);
    }
};
