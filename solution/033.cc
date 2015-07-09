

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int flag = 0;
        int index = -1;
        if (nums.front() > nums.back()){
            flag = 1;
            int l = 0; int r = nums.size() - 1;
            while (l < r - 1){
                int mid = (l + r) / 2;
                if (nums[l] > nums[mid]) r = mid; else
                    l = mid;
            }
            auto res = equal_range(nums.begin(), nums.begin() + r, target);
            if (res.first != res.second){
                index = res.first - nums.begin();
            }
            res = equal_range(nums.begin() + r, nums.end(), target);
            if (res.first != res.second){
                index = res.first - nums.begin();
            }
        }
        else{
            auto res = equal_range(nums.begin(), nums.end(), target);
            if (res.first != res.second){
                index = res.first - nums.begin();
            }
        }

        return index;
    }
};