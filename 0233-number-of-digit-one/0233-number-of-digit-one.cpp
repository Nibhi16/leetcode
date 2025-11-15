#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            res += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return res;
    }
};
