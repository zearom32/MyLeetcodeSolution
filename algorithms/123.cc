/*
bidirection search
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<int> p1; p1.resize(len);
        vector<int> p2; p2.resize(len);
        int mint = prices[0];
        for (int i = 1; i < len; i++){
            p1[i] = max(p1[i-1],prices[i] - mint);
            mint = min(mint,prices[i]);
        }
        int maxt = prices[len-1];
        for (int i = len - 2; i >= 0; i--){
            p2[i] = max(p2[i+1],maxt - prices[i]);
            maxt = max(maxt,prices[i]);
        }
        int ans = 0;
        for (int i = 0; i <len-1; i++){
            ans = max(ans,p1[i]+p2[i+1]);
        }
        ans = max(ans,p1[len-1]);
        return ans;
    }
};