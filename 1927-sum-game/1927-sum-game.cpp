//"2582?9"
class Solution {
public:
    bool sumGame(string num) {
        double ans = 0;

        int n = num.size();

        for (int i = 0; i < n / 2; i++)
            ans += (num[i] == '?' ? 4.5 : num[i] - '0');

        for (int i = n / 2; i < n; i++)
            ans -= (num[i] == '?' ? 4.5 : num[i] - '0');

        return ans != 0;
    }
};