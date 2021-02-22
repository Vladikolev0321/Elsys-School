package com.company;

public class Citizen extends Human implements ICommunist{

    public Citizen(String name, int age) {
        super(name, age);
    }

    @Override
    boolean canTravel() {
        return false;
    }

    @Override
    public boolean canPerformGenocide() {
        return false;
    }

    @Override
    public void vote() {

    }
}
