class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0, n=x;
        while(x>0)
        {
            int rem=x%10;
             
             if(rev>INT_MAX/10||(rev==INT_MAX/10 && rem>7))
             return false;
             
            rev = rev*10+rem;
            x=x/10;
        }

        return rev==n;
    }
};