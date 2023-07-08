class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //base case
        if(n == 0){
            return 0;
        }
        unordered_map<int, int> mp;  //{prefix_sum, count}
        int count = 0;
        int curr_sum = 0;
        for(int i : nums){
            curr_sum += i;
            if(curr_sum == k){
                count++;
            }
            if(mp.find(curr_sum - k) != mp.end()){
                count += mp[curr_sum - k];
            }
            if(mp.find(curr_sum) != mp.end()){
                mp[curr_sum] += 1;
            }
            else{
                mp[curr_sum] = 1;
            }
        }
        return count;
    }
};