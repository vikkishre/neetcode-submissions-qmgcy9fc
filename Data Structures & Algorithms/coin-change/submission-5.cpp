class Solution {
public:
    vector<int> dp;
    int helper(int amount,vector<int>& coins)
    {
        if(amount==0)
        {
            return 0;
        }
        else if(amount<0){
            return -1;
        }
        if(dp[amount]!=-2)
            return dp[amount];
        int result=INT_MAX;
        for(int coin:coins)
        {
            int res1=helper(amount-coin,coins);
            if(res1!=-1)
            {
                res1=1+res1;
                result=min(result,res1);
            }
        }
        return dp[amount]=result==INT_MAX?-1:result;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-2);
        return helper( amount,coins);


    }
};
