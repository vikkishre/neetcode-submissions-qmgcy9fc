class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        dp[0]=1;
        int maxLen=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            maxLen=0;
            for(int j=0;j<i;j++)
            {
                
                        if(nums[j]<nums[i])
                        {
                           maxLen= max(maxLen,dp[j]);
                        }
            }
            dp[i]=maxLen+1;
            
        }
        int large=INT_MIN;
        for(int num:dp)
        {
            if(num>large)
            {
                large=num;
            }
        }
        return large;
    }
};
