class Solution {
    public boolean check(int[] nums) {
        int l=nums.length;
        int c=0;
        for(int i=0;i<l;i++)
        {
            if(nums[i]>nums[(i+1)%l])
            c++;
        }
        return c<=1;
    }
}