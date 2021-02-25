package com.company;

public class Weapon extends Items{

    public int damage;

    public Weapon(String name, int damage){
        super(name);
        this.damage = damage;
    }

    @Override
    public String toString() {
        return "Weapon{" +
                "damage=" + damage +
                '}';
    }
}
