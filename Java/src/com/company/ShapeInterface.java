package com.company;
 /*
    every member of interface is only and only public whether you define or not.
    interface members can only be public...
 */
interface ShapeInterface{
    void draw();
    double circumference();
}

class Triangle implements ShapeInterface {
    int edgeA;
    int edgeB;
    int edgeC;
    Triangle(int a, int b, int c) {
        this.edgeA = a;
        this.edgeB = b;
        this.edgeC = c;
    }
    @Override
    public void draw() {
        System.out.println("Draw Triangle" + " x = " + this.edgeA + " y = " + this.edgeB + " z = " + this.edgeC);
    }

    @Override
    public double circumference() {
        return (double) this.edgeA + this.edgeB + this.edgeC;
    }
}

interface A {
    interface B{
        void show();
    }
}
class C implements A.B {
    public void show(){
        System.out.println("C B A");
    }
}
class Test{
    interface NestedInterface {
         void show();
    }
}

class Testing implements Test.NestedInterface {
    public void show() {
        System.out.println("NestedInterface");
    }
}
class Run{
    public static void main(String args[]) {
        Test.NestedInterface obj;
        Testing obj2 = new Testing();
        obj = obj2;
        obj.show();
    }
}
