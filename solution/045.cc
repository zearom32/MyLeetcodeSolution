class Solution {
public:
    int jump(int A[], int n) {
        vector<int> f;
        vector<int> b;
        f.reserve(n);
        b.reserve(n);
        f[n - 1] = 0;
        b[0] = n - 1;
        int sz = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            auto p = lower_bound(b.begin(), b.begin() + sz, A[i] + i, greater<int>());
            if (p == b.begin() + sz) p--;
            f[i] = f[*p] + 1;
            int j = sz - 1;
            while (j >= 0 && f[i] <= f[b[j]]) j--;
            b[++j] = i;
            sz = j + 1;
        }
        return f[0];
    }
};