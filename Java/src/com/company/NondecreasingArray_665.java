package com.company;
// 665. Non-decreasing Array
public class NondecreasingArray_665 {
    // array[i] <= array[i + 1]
    public boolean checkPossibility(int[] nums) {
        int len = nums.length, l = len - 1, r = 0;
        for(int i = 0; i < len; i++) {
            if (i + 1 < len && nums[i] > nums[i + 1]) {
                l = i;
                break;
            }
        }
        for(int i = len - 1; i >= 0; i--) {
            if (i - 1 >= 0 && nums[i - 1] > nums[i]){
                r = i;
                break;
            }
        }
        System.out.println(l + " " + r);
        if (l == len - 1 && r == 0) return true;
        if (l + 1 != r) return false;
        if (r + 1 < len && l - 1 >= 0) return nums[l] <= nums[r + 1] || nums[l - 1] <= nums[r];
        return true;
    }
    public static void main(String args[]) {
        NondecreasingArray_665 s = new NondecreasingArray_665();
        int[] nums = {3,2,1};
        boolean ans = s.checkPossibility(nums);
        System.out.println(ans);
    }
}
