package com.company;

public class Armour extends Items{
    public int defense;

    public Armour(String name, int defense){
        super(name);
        this.defense = defense;
    }

    @Override
    public String toString() {
        return "Armour{" +
                "defense=" + defense +
                '}';
    }
}
