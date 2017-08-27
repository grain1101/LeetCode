package com.company;

public class StringtoInteger_8 {
    public int myAtoi(String str) {
        int ret = 0, sign = 1, index = 0;
        if (str.length() == 0) return 0;
        while (index < str.length() && str.charAt(index) ==  ' ') {
            index++;
        }
        if (index < str.length() && str.charAt(index) == '+' || str.charAt(index) == '-') {
            sign = str.charAt(index) == '+' ? 1 : -1;
            index++;
        }
        while (index < str.length()) {
            int digit = str.charAt(index) - '0';
            if (digit < 0 || digit > 9) break;
            if (Integer.MAX_VALUE / 10 < ret || Integer.MAX_VALUE / 10 == ret && Integer.MAX_VALUE % 10 < digit) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            ret = ret * 10 + digit;
            index++;
        }
        return ret * sign;
    }
    public static void main(String args[]) {
        StringtoInteger_8 s = new StringtoInteger_8();
        String str = "    -123";
        System.out.println(str);
        System.out.println(s.myAtoi(str));
    }
}
