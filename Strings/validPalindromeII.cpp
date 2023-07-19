class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return isPalindrome(i+1, j, s) || isPalindrome(i, j-1, s);
            }
        }
        return true;
    }
};