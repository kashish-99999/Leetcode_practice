class Solution {
public:
    int countCommas(int n) {
        int digit =0;
        for(int i=1;i<=n;i++)
        {
            if(i>=1000)
            digit++;
        }

        return digit;
    }
};