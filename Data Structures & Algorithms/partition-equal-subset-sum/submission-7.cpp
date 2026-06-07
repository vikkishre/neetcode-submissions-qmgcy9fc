class Solution {
public:
    int helper(int i,int sum,double target,vector<int>&nums)
    {
        if(sum==target)
            return true;
        if(i>=nums.size())
            return false;
        return helper(i+1,sum+nums[i],target,nums) || helper(i+1,sum,target,nums);
    }
    bool canPartition(vector<int>& nums) {
        double sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return helper(0,0,sum/2,nums);
    }
};
