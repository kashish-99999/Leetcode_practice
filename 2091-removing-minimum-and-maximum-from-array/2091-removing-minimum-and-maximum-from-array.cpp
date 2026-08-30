class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int m1=min_element(nums.begin(),nums.end())-nums.begin();
        int m2=max_element(nums.begin(),nums.end())-nums.begin();

        if (m1 > m2)  swap(m1, m2);

        int start=m2+1;
        int end=n-m1;
        int se=m1+1+n-m2;

        return min({start,end,se});
    }
};