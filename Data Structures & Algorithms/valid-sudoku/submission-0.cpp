class Solution {
public:
    bool validRows(vector<vector<char>> &b){
        for(int i = 0 ; i < 9 ; i++){
            vector<int>f(10,0);
            for(int j = 0 ; j < 9 ; j++){
                if(b[i][j] != '.'){
                    if(f[b[i][j] - '0'] > 0) return false;
                    f[b[i][j] - '0']++;
                }
            }
        }

        return true;
    }

    bool validColumns(vector<vector<char>> &b){
        for(int i = 0 ; i < 9 ; i++){
            vector<int>f(10,0);
            for(int j = 0 ; j < 9 ; j++){
                if(b[j][i] != '.'){
                    if(f[b[j][i] - '0'] > 0) return false;
                    f[b[j][i] - '0']++;
                }
            }
        }

        return true;
    }

    bool validSquares(vector<vector<char>>&b){
        for(int i = 0 ; i < 9 ; i+=3){
            for(int j = 0  ; j < 9 ; j+=3){
                vector<int>f(10,0);
                for(int k = i ; k < i + 3 ; k++){
                    for(int l = j ; l < j +3 ; l++){
                        if(b[k][l] != '.'){
                            if(f[b[k][l] - '0'] > 0) return false;
                            f[b[k][l] - '0']++;
                        }
                    }
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return (validRows(board) && validColumns(board) && validSquares(board));
    }
};
