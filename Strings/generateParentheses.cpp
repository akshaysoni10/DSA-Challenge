class Solution {
public:
    vector<string> ans;
    void getParenthesis(int start, int end, int n, string curr){
        //base case
        if(curr.length() == n*2){
            ans.push_back(curr);
            return;
        }
        if(start < n){
            getParenthesis(start + 1, end, n, curr + "(");
        }
        if(end < start){
            getParenthesis(start, end + 1, n, curr + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        getParenthesis(0, 0, n, "");
        return ans;
    }
};