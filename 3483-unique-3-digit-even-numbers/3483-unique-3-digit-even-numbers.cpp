class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int d =0;
        int seen[1000]={0};
        int n=digits.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j || j==k || i==k)
                    continue;

                    int num=digits[i]*100+digits[j]*10+digits[k];

                    if(num>=100 && num%2==0)
                    seen[num]=1;
                }
            }
        }

        int ans=0;
        for(int i=100;i<1000;i++)
        {
            ans=ans+seen[i];
        }

        return ans;
    }
};