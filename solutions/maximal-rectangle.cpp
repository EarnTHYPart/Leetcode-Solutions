class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m, 0); 

        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0; 
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!s.empty() && heights[s.top()] >= currentHeight) {
                int poppedHeightIndex = s.top();
                s.pop();

                long long height = heights[poppedHeightIndex];
                long long width;

                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                
                maxArea = max(maxArea, static_cast<int>(height * width));
            }
            s.push(i);
        }

        return maxArea;
    }
};
