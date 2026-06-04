class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prefix = 0, suffix = 0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            //maxi1=max(maxi1,nums[i]);
           prefix=nums[i]*(prefix==0?1:prefix);
           suffix=nums[nums.size()-1-i]*(suffix==0?1:suffix);
            res=max(res,max(prefix,suffix));
        }
        return res;
    }
};
