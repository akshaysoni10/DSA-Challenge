class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //brute force solution
        int n = points.size();
        int maxi = INT_MIN;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff = abs(points[i][0] - points[j][0]);
                if(diff <= k){
                    int value = points[i][1] + points[j][1] + diff;
                    maxi = max(maxi, value);
                }
                else{
                    continue;
                }
            }
        }
        return maxi;
        
        //Optimized solution using priority_queue
        priority_queue<pair<int, int>> pq;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            while(!pq.empty() && ((points[i][0] - pq.top().second) > k)){
                pq.pop();
            }
            if(!pq.empty()){
                int value = points[i][0] + points[i][1] + pq.top().first;
                maxi = max(maxi, value);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return maxi;
    }
};