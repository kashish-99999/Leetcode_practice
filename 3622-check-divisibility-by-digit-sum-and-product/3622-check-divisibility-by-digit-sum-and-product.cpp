class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int x = n;

        while (x) {
            int digit = x % 10;
            sum += digit;
            prod *= digit;
            x /= 10;
        }

        return n % (sum + prod) == 0;
    }
};