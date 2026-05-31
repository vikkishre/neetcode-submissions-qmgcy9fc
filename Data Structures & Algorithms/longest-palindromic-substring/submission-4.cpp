class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,j=0;
        string res="";
        while(i<s.length())
        {
            int l=i,h=j;
            int curLength=0;
            while(l>=0 && h<s.length())
            {
                if(s[l]==s[h])
                {
                    curLength=h-l+1;
                    if(curLength>res.length())
                    {

                        res=s.substr(l,h-l+1);
                    }
                }
                else{
                    break;
                }
                l--;
                h++;
            }
            i++;
            j++;
        }
        i=0,j=1;
        while(j<s.length())
        {
            int l=i,h=j;
            int curLength=0;
            while(l>=0 && h<s.length())
            {
                 if(s[l]==s[h])
                 {
                    curLength=h-l+1;
                    if(curLength>res.length())
                    {
                        res=s.substr(l,h-l+1);
                    }
                 }
                 else
                 {
                    break;
                 }
                l--;
                h++;
            }
            i++;
            j++;
        }
        return res;
    }
};
