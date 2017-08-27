package com.company;

import java.util.Arrays;
import java.util.Collections;
/*
trim() : string with omitted leading and trailing spaces
split()
*/

public class ReverseWordsInString_151 {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
    static public  void main(String args[]) {
        String str = "    hello   world  123  3  56  ";
        String tmp =  str.trim();
        String[] words = tmp.split("\\s");
        for(String w : words) {
            if (w.length() == 0) continue;
            System.out.println(w);
        }
//        ReverseWordsInString_151 s = new ReverseWordsInString_151();
//        System.out.println(s.reverseWords(str));
    }
}
