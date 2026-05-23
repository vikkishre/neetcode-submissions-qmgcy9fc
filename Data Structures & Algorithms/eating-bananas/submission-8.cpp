class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high)
        {
            int mid = low + (high - low)/2;

            long long hr = 0;

            for(int bananas : piles)
            {
                hr += (bananas + mid - 1)/mid;
            }

            if(hr <= h)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};