class Solution {
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        //base case
        if(m == 0 || n == 0){
            return 0;
        }
        if(n < m){
            return -1;
        }
        int mini = INT_MAX;
        for(int i=0; i+m-1<n; i++){
            if(a[i+m-1] - a[i] < mini){
                mini = a[i+m-1] - a[i];
            }
        }
        return mini;
    }
};
