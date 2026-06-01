class Solution {
public:
    int countSubstrings(string s) {
        int i=0,j=0;
        int pal=0;
        while(i<s.length())
        {
            int l=i,h=j;
            while(l>=0 && h<s.length())
            {
                if(s[l]==s[h])
                {
                    pal++;
                    l--;
                    h++;
                }
                else{
                    break;
                }
            }
            i++;
            j++;
        }
        i=0,j=1;
        while(j<s.length())
        {
            int l=i,h=j;
            while(l>=0 && h<s.length())
            {
                if(s[l]==s[h])
                {
                    pal++;
                    l--;
                    h++;
                }
                else{
                    break;
                }
            }
            i++;
            j++;
        }
        return pal;
    }
};
