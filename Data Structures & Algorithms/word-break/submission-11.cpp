class Solution {
public:
    vector<int> dp;
    bool helper(string s,vector<string>& wordDict,int i)
    {
        if(i==s.length())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        for(string w:wordDict)
        {
            if(i+w.length()<=s.length() && s.substr(i,w.length())==w)
                if(helper(s,wordDict,i+w.length()))
                {
                    dp[i]=1;
                    return true;
                    
                }
                    
        }
        dp[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length()+1,-1);
        dp[s.length()]=true;
        return helper(s,wordDict,0);
    }
};
