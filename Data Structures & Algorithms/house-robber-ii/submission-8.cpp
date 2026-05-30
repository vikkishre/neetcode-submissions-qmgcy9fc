class Solution {
public:
    vector<int> dp;
    //vector<int> dp1;
    int helper(int i,int n,vector<int>& nums)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int res1=nums[i]+helper(i+2,n,nums);
        int res2=helper(i+1,n,nums);
        return dp[i]=max(res1,res2);
    }
    // int helper1(int i,int n,vector<int>& nums)
    // {
    //     if(i>=n)
    //         return 0;
    //     if(dp1[i]!=-1)
    //         return dp[i];
    //     int res1=nums[i]+helper1(i+2,n,nums);
    //     int res2=helper1(i+1,n,nums);
    //     return dp1[i]=max(res1,res2);
    // }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        dp.resize(nums.size()+1,-1);
        int res1=helper(0,nums.size()-1,nums);
        dp.clear();
        dp.resize(nums.size()+1,-1);
        int res2=helper(1,nums.size(),nums);
        return max(res1,res2);
    }
};
