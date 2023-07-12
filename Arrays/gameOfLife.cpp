class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        if(x >= 0 && x < m && y >= 0 && y < n){
            return true;
        }
        else{
            return false;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        //8 directions to move
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};
        
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                int count = 0;
                for(int i=0; i<8; i++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];
                    if(isValid(nx, ny, board) && abs(board[nx][ny]) == 1){
                        count++;
                    }
                }
                if(board[row][col] == 1 && (count < 2 || count > 3)){
                    board[row][col] = -1;
                }
                if(board[row][col] == 0 && count == 3){
                    board[row][col] = 2;
                }
            }
        }
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(board[row][col] >= 1){
                    board[row][col] = 1;
                }
                else{
                    board[row][col] = 0;
                }
            }
        }
    }
};