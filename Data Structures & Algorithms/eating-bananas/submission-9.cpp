class Solution {
public:
    int maxElement(vector<int> &piles)
    {
        int max=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>max)
                max=piles[i];
        }
        return max;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxElement(piles);
        int hr;
        while(low<high)
        {
            hr=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<piles.size();i++)
            {
                hr+=ceil((double)piles[i]/mid);
            }
            if(hr<=h)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
