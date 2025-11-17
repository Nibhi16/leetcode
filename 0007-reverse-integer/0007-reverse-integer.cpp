class Solution {
public:
    int reverse(int x) {
        long long rev = 0;   // use long long to safely detect overflow
        
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;

            // check for 32-bit overflow
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0;
            }

            x /= 10;
        }

        return (int)rev;
    }
};
