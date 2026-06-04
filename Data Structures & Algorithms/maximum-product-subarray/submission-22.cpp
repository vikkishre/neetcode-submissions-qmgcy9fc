class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=nums[0];
        int suffix=nums[nums.size()-1];
        int maxi1=prefix;
        int maxi2=suffix;
        for(int i=1;i<nums.size();i++)
        {
            if(prefix==0)
            {
                prefix=nums[i];
            }
            else{
                prefix*=nums[i];
            }
            maxi1=max(maxi1,prefix);
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(suffix==0)
                suffix=nums[i];
            else{
                suffix*=nums[i];
            }
            maxi2=max(maxi2,suffix);
        }
        return max(maxi1,maxi2);
    }
};
