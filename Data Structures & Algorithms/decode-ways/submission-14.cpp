class Solution {
public:
    vector<int> dp;
    int helper(int i,string &s)
    {
        if(i==s.length())
            return 1;
        
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ways=helper(i+1,s);
        if(i+1<s.length())
        {
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26)
            {
                ways+=helper(i+2,s);
            }
        }
        return dp[i]=ways;
    }
    int numDecodings(string s) {
        dp.resize(s.length(),-1);
        return helper(0,s);
    }
};
