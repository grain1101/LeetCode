package com.company;
/*Method is overridden not the datamembers, so runtime polymorphism can't be achieved by data members.*/
public class Honda extends Bike{
    int speed = 120;
    void getSpeed() {
        System.out.println("Hongda's" + this.speed);
    }
    public static void main(String args[]) {
        Bike b = new Honda();
        System.out.println(b.speed);
    }
}
