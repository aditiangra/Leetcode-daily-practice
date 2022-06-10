class Solution {
public:
    int numTrees(int n) {
        // Catalan Number can be given by
        // (2*nCn) / (n+1)
        long long int ans = 1;
        for(int i=0 ; i<n ; i++)
        {
            ans *= 2*n-i;
            ans /= i+1;
        }
        return ans/(n+1);
    }
};