class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        // Add boundaries
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDiffs;

        // Store all horizontal distances
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long best = 0;

        // Check vertical distances from largest to smallest
        for (int i = vFences.size() - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                int d = vFences[i] - vFences[j];
                if (d <= best) break;   // pruning
                if (hDiffs.count(d)) {
                    best = d;
                }
            }
        }

        if (best == 0) return -1;

        const long long MOD = 1e9 + 7;
        return (best * best) % MOD;
    }
};
