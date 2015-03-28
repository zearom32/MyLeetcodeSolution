class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        int ans = 0;
        int l[n], r[n], h[n];
        fill(l, l + n, 0);
        fill(h, h + n, 0);
        fill(r, r + n, n - 1);
        for (int i = 0; i < m; i++){
            int k = 0;
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1'){
                    l[j] = max(l[j], k);
                    h[j]++;
                }
                else
                {
                    h[j] = 0;
                    l[j] = 0; k = j + 1;
                }
            }
            k = n - 1;
            for (int j = n - 1; j >= 0; j--){
                if (matrix[i][j] == '1'){
                    r[j] = min(r[j], k);
                }
                else{
                    r[j] = n - 1;
                    k = j - 1;
                }
            }
            for (int j = 0; j < n; j++){
                ans = max(ans, (1 + r[j] - l[j])*h[j]);
            }
        }
        return ans;
    }
};