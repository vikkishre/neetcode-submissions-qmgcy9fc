class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,h=nums.size()-1;
        int mini=nums[0];

        while(l<=h)
        {
            if(nums[l]<=nums[h])
            {
                mini=min(mini,nums[l]);
                break;
            }

            int mid=l+(h-l)/2;

            mini=min(mini,nums[mid]);

            if(nums[mid]>=nums[l])
                l=mid+1;
            else
                h=mid-1;
        }

        return mini;
    }
};