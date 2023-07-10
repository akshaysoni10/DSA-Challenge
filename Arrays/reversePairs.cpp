class Solution {
public:
    //T.C. - O(logn) + O(n) 
    //S.C. - O(n)
    int merge(vector<int> &nums, int low, int mid, int high){
        int count = 0;
        int j = mid + 1;
        for(int i=low; i<=mid; i++){
            while(j <= high && nums[i] > 2LL * nums[j]){
                j++;
            }
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        int left = low, right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        while(right <= high){
            temp.push_back(nums[right++]);
        }
        for(int i=low; i<=high; i++){
            nums[i] = temp[i - low];
        }
        return count;
    }
    
    int mergeSort(vector<int> &nums, int low, int high){
        //base case
        if(low >= high){
            return 0;
        }
        int mid = (low + high) / 2;
        int s = mergeSort(nums, low, mid);  //sort left part
        s += mergeSort(nums, mid + 1, high);  //sort right part
        s += merge(nums, low, mid, high);  //merge whole array(left + right)
        return s;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};