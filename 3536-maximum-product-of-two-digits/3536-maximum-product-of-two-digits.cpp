class Solution {
public:
    int maxProduct(int n) {
        int digits=0,pro=0,x=0,y=0;
        while(n>0)
        {
            digits=n%10;
            if(digits>x)
            {
                y=x;
                x=digits;
            }
            else if(digits>y)
            {
                y=digits;
            }
            n=n/10;
             pro=x*y;
        }

        return pro;
    }
};