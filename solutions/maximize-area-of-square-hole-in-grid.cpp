class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int c = 1;
        int maxHorizontal = 1;
        int maxVertical = 1;

        for(int i = 1 ; i < hBars.size() ; i++)
        {
            if(hBars[i] == hBars[i-1] + 1)
                c++;
            else
                c =1;
            maxHorizontal = max(maxHorizontal , c);
        }
        c = 1;
        for(int i = 1 ; i < vBars.size() ; i++)
        {
            if(vBars[i] == vBars[i-1] + 1)
                c++;
            else
                c =1;
            maxVertical = max(maxVertical, c);
        }

        int side = min(maxHorizontal , maxVertical) + 1;
        return side*side;
    }
};
