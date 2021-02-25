package com.company;

public class Potion extends Items{

    public Potion(String name){
        super(name);
    }

    @Override
    public String toString() {
        return "Potion{" + name +"}";
    }
}
