class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int j = 0;
        while (j < n){
            int k = A[j];
            if (k == j + 1) { j++; continue; }
            if (A[j] > n || A[j] <= 0){ A[j] = -1; j++; continue; }
            else{
                if (A[k - 1] == k){ A[j] = -1; continue; }
                int temp = A[k - 1];
                A[k - 1] = A[j];
                A[j] = temp;
            }
        }
        for (int i = 0; i < n; i++){
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};