package com.company;

public class InnerClass implements Cloneable {
    int cnt;
    InnerClass() {
    }
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    public static void main(String args[]) throws CloneNotSupportedException {
        OuterClass o = new OuterClass("outer");
        InnerClass s = new InnerClass();
        Object c = s.clone();
    }
}
