package com.company;

public class Ruler extends Human implements ICommunist{

    public Ruler(String name, int age) {
        super(name, age);
    }

    @Override
    boolean canTravel() {
        System.out.println("Ruler can travel?");
        return true;
    }

    @Override
    public boolean canPerformGenocide() {
        return false;
    }

    @Override
    public void vote() {
        System.out.println("I voted for 2500 votes");
    }
}
