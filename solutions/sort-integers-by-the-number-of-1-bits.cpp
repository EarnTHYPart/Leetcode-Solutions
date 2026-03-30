class Solution {
public:
    vector<int> sortByBits(vector<int>& numbers) {

        vector<vector<int>> bitCountBuckets(15);

        for(int number : numbers) {
            int setBitCount = __builtin_popcount(number);
            bitCountBuckets[setBitCount].push_back(number);
        }

        vector<int> sortedResult;

        for(auto &bucket : bitCountBuckets) {
            sort(bucket.begin(), bucket.end());
            for(int number : bucket)
                sortedResult.push_back(number);
        }

        return sortedResult;
    }
};
