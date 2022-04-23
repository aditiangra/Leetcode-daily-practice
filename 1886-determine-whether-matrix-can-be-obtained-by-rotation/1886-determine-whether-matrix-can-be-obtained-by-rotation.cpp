class Solution {
    void rotateMatrixClockwiseInPlace(vector<vector<int>>& mat)
    {
        // * flip vertically
        reverse(begin(mat), end(mat));

        // * transpose
        for (int i = 1; i < size(mat); i++)
            for (int j = 0; j < i; j++)
                swap(mat[i][j], mat[j][i]);
    }

   public:
    bool findRotation(vector<vector<int>>& mat, const vector<vector<int>>& target)
    {
        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        return mat == target;
    }
};