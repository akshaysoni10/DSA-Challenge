class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(long i=0; i<n; ++i){
            for(long j=i+1; j<n; ++j){
                long long tar_sum = long(target) - long(nums[i]) - long(nums[j]);
                long l = j+1, h = n-1;
                while(l < h){
                    if(nums[l] + nums[h] == tar_sum){
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                        ++l;
                        --h;
                        while(l < h && nums[l-1] == nums[l]){
                            ++l;
                        }
                    }
                    else if(nums[l] + nums[h] > tar_sum){
                        --h;
                    }
                    else{
                        ++l;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]){
                    ++j;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]){
                ++i;
            }
        }
        return ans;
    }
};