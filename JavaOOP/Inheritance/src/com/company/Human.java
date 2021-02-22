package com.company;

public abstract class Human {
    String name;
    int age;

    public Human(String name, int age) {
        this.name = name;
        this.age = age;
    }

    abstract boolean canTravel();
    public abstract boolean canPerformGenocide();


}
