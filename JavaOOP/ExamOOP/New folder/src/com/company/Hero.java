package com.company;

import java.util.List;

public abstract class Hero {
    protected int level;
    protected int strenght;
    protected int intelligence;
    protected String specialisation;

    public Hero() {

    }
    public Hero(int level, int strenght, int intelligence, String specialisation) {
        this.level = level;
        this.strenght = strenght;
        this.intelligence = intelligence;
        this.specialisation = specialisation;
    }



    public abstract int getPower(List<Hero> party, Monster monster);
}
