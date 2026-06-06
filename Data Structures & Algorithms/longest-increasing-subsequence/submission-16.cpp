class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i+1]=max(dp[i+1],dp[j+1]+1);
            }
            if(dp[i+1]==-1)
                dp[i+1]=1;
        }
        int max=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>max)
                max=dp[i];
        }
        return max;
    }
};
