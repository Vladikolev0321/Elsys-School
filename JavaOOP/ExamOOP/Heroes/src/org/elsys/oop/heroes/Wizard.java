package org.elsys.oop.heroes;

import java.util.List;

public class Wizard extends Hero{


    public Wizard(int level, int strenght, int intelligence, String specialisation) {

        if(specialisation != "Cleric" && specialisation != "Sorcerer" && specialisation != "Warlock"){
            throw new IllegalArgumentException("Invalid specialisation");
        }
        this.level = level;
        this.strenght = strenght;
        this.intelligence = intelligence;
        this.specialisation = specialisation;

    }

    @Override
    public int getPower(List<Hero> party, Monster monster) {
        int resPower = this.level * this.intelligence;
        if(specialisation == "Cleric"){
           if(monster.getCharacteristics().contains("Darkness") || monster.getCharacteristics().contains("Evil")){
               resPower += resPower * 0.25;
           }
        }else if(specialisation == "Sorcerer"){
            if(monster.getCharacteristics().contains("Summoned") || monster.getCharacteristics().contains("Evil")){
                resPower += resPower * 0.25;
            }
        }else{
            if(monster.getCharacteristics().contains("Holy")){
                resPower += resPower * 0.25;
            }
        }
        return resPower;
    }
}
