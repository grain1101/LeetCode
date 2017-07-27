class Solution {
public:
    int search(vector<int>& nums, int target) {
    // left part is larger equal than nums[0]
    // right part is less than nums[0]
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 0) return -1;
        
        if (isLeftPart(nums, r)) return binarySearch(nums, l, r, target);
        if (l == r) return nums[l] == target ? l : -1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if (isLeftPart(nums, mid)) l = mid;
            else r = mid;
        }
        if(target >= nums[0]) return binarySearch(nums, 0, l, target);
        else return binarySearch(nums, r, nums.size() - 1, target);
    }
    bool isLeftPart(vector<int>& nums, int idx){
        return nums[idx] >= nums[0];
    }
    int binarySearch(vector<int>& nums, int l, int r, int target){
        if (!isLeftPart2(nums, l, target)) return nums[l] == target ? l : -1;
        if (isLeftPart2(nums, r, target)) return -1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if (isLeftPart2(nums, mid, target)) l = mid;
            else r = mid;
        }
        return nums[r] == target ? r : -1;
    }
    // left part is less than target
    bool isLeftPart2(vector<int>& nums, int idx, int target){
        return nums[idx] < target;
    }
};