class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size();
        long long zero = 0;

        for(char c : s)
            if(c == '0')
                zero++;

        if(zero == 0)
            return 0;

        long long one = n - zero;

        for(long long op = 1 ; op <= n ; op++)
        {
            long long totalFlip = op * 1LL * k;
            if((totalFlip - zero) % 2 != 0)
                continue;
            
            if(op%2 == 1)
            {
                if (totalFlip >= zero && totalFlip <= zero * op + one * (op - 1))
                    return op;
            }
            else
            {
                if(totalFlip >= zero && totalFlip <= zero * (op - 1) + one * op)
                    return op;
            }
        }
        return -1;
    }
};
