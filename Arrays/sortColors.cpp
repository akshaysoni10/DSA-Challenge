class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, mid = 0, end = n - 1;
        while(mid <= end){
            switch(nums[mid]){
                case 0:
                    swap(nums[mid++], nums[start++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[end--]);
                    break;
            }
        }
    }
};