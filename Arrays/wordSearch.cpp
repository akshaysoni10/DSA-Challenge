class Solution {
public:
    bool search(int k, int i, int j, int &m, int &n, vector<vector<char>>& board, string &word){
        //base case
        if(k == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] != word[k] || board[i][j] == '#'){
            return false;
        }
        
        char ch = board[i][j];
        board[i][j] = '#';
        bool op1 = search(k+1, i+1, j, m, n, board, word);
        bool op2 = search(k+1, i, j+1, m, n, board, word);
        bool op3 = search(k+1, i-1, j, m, n, board, word);
        bool op4 = search(k+1, i, j-1, m, n, board, word);
        board[i][j] = ch;
        return op1 || op2 || op3 || op4;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //base case
        if(word.size() == 0){
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(search(0, i, j, m, n, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};