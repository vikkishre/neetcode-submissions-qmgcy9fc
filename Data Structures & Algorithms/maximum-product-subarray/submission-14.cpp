class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        prefix[0]=nums[0];
        int maxi1=nums[0];
        int maxi2=nums[nums.size()-1];
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
                continue;
            prefix[i]=nums[i]*prefix[i-1];
            maxi1=max(maxi1,prefix[i]);
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix[i]=nums[i]*suffix[i+1];
            maxi2=max(maxi2,suffix[i]);
        }
        return max(maxi1,maxi2);
    }
};
