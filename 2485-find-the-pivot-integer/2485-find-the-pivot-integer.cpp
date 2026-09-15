class Solution {
public:
    int pivotInteger(int n) {
        int sum1=0;
        int total=n*(n+1)/2;
        for(int i=1;i<=n;i++)
        {
            sum1=sum1+i;
            int sum2= total-sum1+i;

            if(sum1==sum2)  return i;
        }

        return -1;
    }
};