class Solution {
    public int searchInsert(int[] nums, int target) {
        int s=0;
        int n=nums.length;
        int e=n-1;
        int ans=n;
        while(s<=e)
        {
            int m=(s+e)/2;
             if(target<=nums[m])
            {
                ans=m;
                e=m-1;
                
            }
            else
            {
                s=m+1;
            }
        }
        return ans;
    }
}