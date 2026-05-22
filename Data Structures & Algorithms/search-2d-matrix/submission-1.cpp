class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid,low,high;
        low=0;
        high=matrix.size()-1;
        int rowLow=0,rowHigh=matrix[0].size()-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][rowHigh])
            {
                while(rowLow<=rowHigh)
                {
                    int rowMid=rowLow+(rowHigh-rowLow)/2;
                    if(matrix[mid][rowMid]==target)
                        return true;
                    else if(target>matrix[mid][rowMid])
                        rowLow=rowMid+1;
                    else
                        rowHigh=rowMid-1;
                }
                return false;
            }
            else if(target<matrix[mid][0])
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};
