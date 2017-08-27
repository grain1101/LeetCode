package com.company;

public class OuterClass {
    OuterClass() {}
    int cnt = 100;
    String name;
    OuterClass(String name){
        cnt++;
        this.name = name;

    }
//    static void display() {
//        System.out.println(" cnt = " + this.cnt);
//    }
//    public static void main(String args[]) {
//        OuterClass s1 = new OuterClass("s1");
//        OuterClass s2 = new OuterClass("s2");
//        OuterClass s3 = new OuterClass("s3");
//        OuterClass.display();
//
//    }
    static {
        System.out.println("static block");
        //System.exit(0);
    }
}
