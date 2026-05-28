class Solution {
public:
    vector<int> dp;
    int helper(int index,int n,vector<int>&cost)
    {
        if(index>=n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int res1=helper(index+1,n,cost);
        int res2=helper(index+2,n,cost);
        int res=min(res1,res2);

        return dp[index]=cost[index]+res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,-1);
        int res1=helper(0,n,cost);
        int res2=helper(1,n,cost);
        return min(res1,res2);
    }
};
