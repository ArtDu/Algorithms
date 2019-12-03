class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        size_t n = matrix.size();
        size_t m = matrix[0].size();
        vector<vector<int>> mem(n, vector<int>(m, -1));

        int MaxSide = 0;
        findMaxSquareAux(MaxSide, matrix, mem, int(n) - 1, int(m) - 1);
        return MaxSide * MaxSide;
    }

    void findMaxSquareAux(int &maxS, vector<vector<char>> &matrix, vector<vector<int>> &mem, int i, int j) {

        if (mem[i][j] > -1) {
            return;
        }

        if (matrix[i][j] == '0') {
            if (i != 0 && j != 0) {
                findMaxSquareAux(maxS, matrix, mem, i - 1, j - 1);
            }
            if (i != 0) {
                findMaxSquareAux(maxS, matrix, mem, i - 1, j);
            }
            if (j != 0) {
                findMaxSquareAux(maxS, matrix, mem, i, j - 1);
            }
            mem[i][j] = 0;
        } else {
            int fst = 0;
            int snd = 0;
            int trd = 0;
            if (i != 0 && j != 0) {
                findMaxSquareAux(maxS, matrix, mem, i - 1, j - 1);
                fst = mem[i - 1][j - 1];
            }
            if (i != 0) {
                findMaxSquareAux(maxS, matrix, mem, i - 1, j);
                snd = mem[i - 1][j];
            }
            if (j != 0) {
                findMaxSquareAux(maxS, matrix, mem, i, j - 1);
                trd = mem[i][j - 1];
            }

            mem[i][j] = min({fst, snd, trd}) + 1;
            maxS = max(maxS, mem[i][j]);

        }


    }
};
