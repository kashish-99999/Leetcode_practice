class Solution {
    public int smallestNumber(int n, int t) {
        for(int num=n; ; num++)
        {
            int pro=1;
            int x=num;
            while(x>0)
            {
                pro=pro*(x%10);
                x=x/10;
            }

            if(pro%t==0)
            {
                return num;
            }
        }
    }
}