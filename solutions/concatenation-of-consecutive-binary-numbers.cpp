class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bit = 0;

        for(int i = 1 ; i <= n ; i++)
        {
            if((i & (i-1)) == 0)
                bit++;
            result = ((result<<bit)| i) % MOD;
        }
        return result;
    }
};
