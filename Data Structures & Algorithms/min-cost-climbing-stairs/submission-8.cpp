class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=cost[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        }
        int min1=dp[n];
        dp.resize(n+1,-1);
        dp[1]=0;
        dp[2]=cost[1];
        for(int i=3;i<=n;i++)
        {
            dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        }
        int min2=dp[n];
        return min(min1,min2);
    }
};
