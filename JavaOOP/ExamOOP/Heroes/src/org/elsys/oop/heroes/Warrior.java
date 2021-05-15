package org.elsys.oop.heroes;

import java.util.List;

public class Warrior extends Hero{


    public Warrior(int level, int strenght, int intelligence, String specialisation) throws IllegalArgumentException{
        //specialisation
        //super(level, strenght, intelligence, specialisation);
        if(specialisation != "Knight" && specialisation != "Barbarian" && specialisation != "Monk"){
            throw new IllegalArgumentException("Invalid specialisation");
        }
        this.level = level;
        this.strenght = strenght;
        this.intelligence = intelligence;
        this.specialisation = specialisation;
    }

    @Override
    public int getPower(List<Hero> party, Monster monster) {
        int resPower = this.level * this.strenght;
        int countCleric = 0;

        if(this.specialisation == "Knight"){
            for (Hero hero : party){
                if(hero.specialisation == "Cleric"){
                    countCleric++;
                }
            }
            resPower += resPower * 0.25;
        }
        return resPower;
    }
}
