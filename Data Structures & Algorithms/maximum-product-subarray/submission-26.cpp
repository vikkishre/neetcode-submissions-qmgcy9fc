class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int cmax=1;
        int cmin=1;
        int prevmax;
        for(int i=0;i<nums.size();i++)
        {
            prevmax=nums[i]*cmax;
            cmax=max(nums[i],max(nums[i]*cmax,nums[i]*cmin));
            cmin=min(nums[i],min(prevmax,nums[i]*cmin));
            res=max(res,cmax);
        }
        return res;
    }
};
