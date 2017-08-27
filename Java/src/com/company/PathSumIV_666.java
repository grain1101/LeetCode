package com.company;

import java.lang.reflect.Array;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;

public class PathSumIV_666 {
    public int ret;
    public int pathSum(int[] nums) {
        ret = 0;
        ArrayList<ArrayList<Integer>> level = new ArrayList<ArrayList<Integer>>(5);
        for(int i = 0; i < 5; i++) {
            level.add(new ArrayList<>());
            for(int j = 0; j < (1<<i); j++) {
                level.get(i).add(null);
            }
        }
        for(int i = 0; i < nums.length; i++) {
            int D = nums[i] / 100;
            int P = nums[i] / 10 % 10;
            int V = nums[i] % 10;
            level.get(D - 1).set(P - 1, V);
        }
        dfs(level, 0, 0, 0);
        System.out.println(this.ret);
        return this.ret;
    }
    public void dfs(ArrayList<ArrayList<Integer>> level, int i, int j, int tmp) {
        if (level.get(i).get(j) == null) return;
        if (level.get(i + 1).get(2 * j) == null && level.get(i + 1).get(2 * j + 1) == null) {
            this.ret += tmp + level.get(i).get(j);
            System.out.println(tmp+ level.get(i).get(j));
            return;
        }
        dfs(level, i + 1, 2 * j, tmp + level.get(i).get(j));
        dfs(level, i + 1, 2 * j + 1, tmp + level.get(i).get(j));
    }
    public void swap(Integer a, Integer b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    public static void main(String args[]) {
        PathSumIV_666 s = new PathSumIV_666();
        int[] nums = {113, 221};
        Integer a = 1, b = 2;
        s.swap(a, b);
        System.out.println("a= " + a + " b = " + b);

        //System.out.println("ans is : " + s.pathSum(nums));
    }
}
