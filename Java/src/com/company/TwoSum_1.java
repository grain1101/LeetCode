package com.company;
import java.util.HashMap;

public class TwoSum_1 {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> m = new HashMap<>();
        if (nums.length == 0) return nums;
        for(int i = 0; i < nums.length; i++) {
            if (m.containsKey(target - nums[i])){
                int[] ret = {m.get(target - nums[i]), i};
                return ret;
            }
            m.put(nums[i], i);
        }
        return nums;
    }
    public static void main(String args[]) {
        int[] nums = {2, 7, 11, 15};
        TwoSum_1 s = new TwoSum_1();
        int[] ans = s.twoSum(nums, 9);
        System.out.println(ans[0] + " " + ans[1]);
    }
}
