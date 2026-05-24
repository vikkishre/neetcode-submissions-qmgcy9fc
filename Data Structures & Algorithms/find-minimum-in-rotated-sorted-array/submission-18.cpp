class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int low=0,high=nums.size()-1;
        if(nums[low]<=nums[high])
            return nums[low];
        if(nums.size()==2)
        {
            if(nums[0]>nums[1])
                return nums[1];
        }
        int mid;
        int mini=INT_MAX;
        while(low<high)
        {
            mid=low+((high-low)/2);
            //mini=min(mini,nums[mid]);
            if(nums[mid]>nums[high])
            {
                //mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                //mini=min(mini,nums[mid]);
                high=mid;
            }

        }
        return nums[low];
    }
};
