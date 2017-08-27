package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class SortByrollno implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {
        return o1.rollno - o2.rollno;
    }
}

class SortbyName implements Comparator<Student> {
    public int compare(Student o1, Student o2) {
        return o1.name.compareTo(o2.name);
    }
}

class SortByAddress implements Comparator<Student> {
    public int compare(Student o1, Student o2) {
        return o1.address.compareTo(o2.address);
    }
}

public class Student {
    int rollno;
    String name, address;
    Student(int rollno, String name, String address){
        this.rollno = rollno;
        this.name = name;
        this.address = address;
    }

    public String toString() {
        return this.rollno + " " + this.name + " " + this.address;
    }

    public static void main(String args[]) {
        Student a = new Student(1, "ccc", "qwe");
        Student b = new Student(2, "bbbb", "asd");
        Student c = new Student(3, "aaa", "zxc");
        ArrayList<Student> arr = new ArrayList<Student>();
        arr.add(a);
        arr.add(b);
        arr.add(c);

        Collections.sort(arr, new SortByrollno());
        for(Student s : arr) {
            System.out.println(s.name);
        }
        Collections.sort(arr, new SortbyName());
        for(Student s : arr) {
            System.out.println(s.name);
        }
        Collections.sort(arr, new SortByAddress());
        for(Student s : arr) {
            System.out.println(s.name);
        }
    }
}



