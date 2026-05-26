class Solution {
    unordered_set<int> s;
public:
    bool isHappy(int n) {
        s.insert(n);
        int temp=n;
        
        while(true)
        {
            int res=0;
            while(temp>0)
            {
                int digit=temp%10;
                res+=pow(digit,2);
                temp=temp/10;
            }
            temp=res;
            if(res==1)
                return true;
            else if(s.find(res)!=s.end())
                break;
            else
                s.insert(res);
        }
        return false;
    }
};
