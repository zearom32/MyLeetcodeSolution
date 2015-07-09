class Solution {
public:
    int findMin(vector<int> &num) {
        int m1 = num[0];
        int n = num.size();
        if (n == 1) return num[0];
        int i = 0; int j = n-1; 
        while (i < n-1 && num[i+1] == num[i]) i++;
        i++;
        if (i > j) i = j;
        if (num[i] < m1) m1 = num[i];
        while(i < j){
            int mid = i + (j-i) / 2;
            if (num[mid] > num[j]){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        int m2 = num[i];
        if (m2 > m1) return m1;
        else return m2;
    }
};