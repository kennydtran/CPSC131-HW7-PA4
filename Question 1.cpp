class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = (h ? matrix[0].size():0); //Declare "h" and assign size of matrix to "h".
                                                             //Declare "w" and assign "h" position of matrix, else 0.
        vector<vector<int>> dp(h, vector<int> (w, 0)); //Declare vector of vector "dp".
        int maxlen = 0; //Declare maxlen (maximum length) and initialize it to 0.
        for (int i = 0; i < h; ++i) //Loop through matrix, left to right each row.
            for (int j = 0; j < w; ++j) 
                maxlen = max(maxlen, dfsSearch(matrix, dp, INT_MIN, i, j)); //Assign DFS searching through matrix to maxlen.
        return maxlen; //Return the maximum length.
    }
    int dfsSearch(vector<vector<int>> &mat, vector<vector<int>> &dp, int prev, int i, int j) { //DFS Function
        int h = mat.size(), w = mat[0].size(); //Declare "h" and assign matrix size. Declare "w" and assign position of matrix.
        if (prev >= mat[i][j]) return 0; //If prev is greater than or equal to matrix, return 0.
        if (dp[i][j])  return dp[i][j]; //Return depth.
        
        int val = mat[i][j]; //Declare val and assign matrix to val.
        int d[4] = {
            i ? dfsSearch(mat, dp, val, i-1, j):0, //Up, recursing through DFS function.
            i+1 < h ? dfsSearch(mat, dp, val, i+1, j):0, //Down, recursing through DFS function.
            j ? dfsSearch(mat, dp, val, i, j-1):0, //Left, recursing through DFS function.
            j+1 < w ? dfsSearch(mat, dp, val, i, j+1):0 //Right, recursing through DFS function.
        };
        return dp[i][j] = max(d[0], max(d[1], max(d[2], d[3]))) + 1; //Return for all rows.
    }
};
