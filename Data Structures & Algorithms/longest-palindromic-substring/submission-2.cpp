class Solution {
public:
    string res="";
    int len;
    void helper(int i,int j,string s)
    {
        len=0;
        int tempI=i,tempJ=j;
        if(tempI< 0 || tempJ>=s.length())
            return;
        while(tempI>=0 && tempJ<s.length())
        {
            if(s[tempI]==s[tempJ])
            {
                len=tempJ-tempI+1;
                if(len>res.length())
                {
                    res=s.substr(tempI,tempJ-tempI+1);
                }
                tempI--;
                tempJ++;
            }
            else{
                break;
            }
        }
        helper(i+1,j+1,s);
    }
    string longestPalindrome(string s) {
        helper(0,0,s);
        helper(0,1,s);
        return res;
    }
};
