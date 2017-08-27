package com.company;

import javafx.scene.shape.Shape;

abstract class ShapeAbstract {
    String objectName = "";
    int centerX = 0;
    int centerY = 0;
    ShapeAbstract(String name){
        this.objectName = name;
    }
    public void moveToCenter() {
        System.out.println(this.objectName + " has been moved to x = " + centerX + ", y = " + centerY);
    }
    public void moveTo(int x, int y) {
        System.out.println(this.objectName + " has been moved to x = " + x + ", y = " + y);
    }
    abstract public double area();
    abstract public void draw();
}

class Rectangle extends ShapeAbstract{
    int length, width;
    Rectangle(int len, int width, String name) {
        super(name);
        this.length = len;
        this.width = width;
    }

    @Override
    public void draw() {
        System.out.println("Draw Rectangle");
    }

    @Override
    public double area() {
        return (double) this.width * this.length;
    }
}

class Circle extends ShapeAbstract {
    int radius;
    final double pi = 3.14;
    Circle(int r, String name) {
        super(name);
        this.radius = r;
    }
    @Override
    public double area() {
        return (double) pi * this.radius;
    }

    @Override
    public void draw() {
        System.out.println("Draw " + this.objectName);
    }
}