class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        //base case
        if(n > m){
            return -1;
        }
        for(int i=0; i<=m; i++){
            string s = haystack.substr(i, n);
            if(s == needle){
                return i;
            }
        }
        return -1;
    }
};