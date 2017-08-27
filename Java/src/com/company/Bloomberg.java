package com.company;

import javafx.scene.effect.Bloom;

import java.util.HashMap;

public class Bloomberg {
    // aaabbca -> abcbccd;
    String countString(String s) {
        String ret = "";
        if (s.isEmpty() || s.length() < 2) return s;
        HashMap<Character, Integer> m = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (m.containsKey(cur)){
                int cnt = (m.get(cur) + 1) % 26;
                m.replace(cur, cnt);
                cur = (char) (cur + cnt);
                System.out.println(i + " " + s.charAt(i) + " " + cur);
            }else {
                m.put(cur, 0);
            }
            ret = ret + cur;
        }
        return ret;
    }
    public static void main(String args[]) {
        String str = "aaabbca";
        Bloomberg s = new Bloomberg();
        String ret = s.countString(str);
        System.out.println(ret);
    }
}
