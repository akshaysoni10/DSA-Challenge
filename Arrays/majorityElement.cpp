class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans_index = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==ans_index){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                ans_index = nums[i];
                count = 1;
            }
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ans_index){
                c++;
            }
        }
        if(c > n/2){
            return ans_index;
        }
        else{
            return -1;
        }
    }
};