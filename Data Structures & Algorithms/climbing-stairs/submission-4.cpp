class Solution {
public:
    vector<int> dp;
    int helper(int index,int n)
    {
        if(index>n)
            return 0;
        else if(index==n)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        return dp[index]=helper(index+1,n)+helper(index+2,n);
    }
    int climbStairs(int n) {
        dp.resize(n,-1);
        return helper(0,n);
    }
};
