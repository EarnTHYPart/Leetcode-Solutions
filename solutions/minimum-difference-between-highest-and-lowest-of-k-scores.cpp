class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        if (n < k)
            return 0;

        int minDiff = INT_MAX;

        for(int i = 0 ; i < n - k + 1  ; i++ )
        { 
            int j = i + k - 1;
            minDiff = min(minDiff , nums[j] - nums[i]);
        }
        return minDiff;
    }
};
