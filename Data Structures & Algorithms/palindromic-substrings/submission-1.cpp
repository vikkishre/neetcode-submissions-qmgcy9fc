class Solution {
public:
    int palindromes=0;
    void helper(int i,int j, string &s)
    {
        int l=i,h=j;
        if(i>=s.length() || j>=s.length())
            return;
        while(l>=0 && h< s.length())
        {
            if(s[l]==s[h])
            {
                palindromes++;
                l--;
                h++;
            }
            else
                break;
        }
        helper(i+1,j+1,s);
    }
    int countSubstrings(string s) {
        helper(0,0,s);
        helper(0,1,s);
        return palindromes;
    }
};
