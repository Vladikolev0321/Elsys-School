package com.company;

import java.util.List;

public class Monster {
    private int level;
    private int strenght;
    private String name;
    private List<String> characteristics;

    public Monster(int level, int strenght, String name, List<String> characteristics) {
        this.level = level;
        this.strenght = strenght;
        this.name = name;
        this.characteristics = characteristics;
    }

    public List<String> getCharacteristics() {
        return characteristics;
    }

    public int getPower(List<Hero> party){
        int resPower = this.level * this.strenght;
        for(var trait : characteristics){
            for(var hero : party) {
                if (trait == "Darkness" && hero.specialisation == "Cleric") {
                    resPower += resPower * 0.25;
                } else if (trait == "Evil" && (hero.specialisation == "Knight" || hero.specialisation == "Monk")) {
                    resPower += resPower * 0.25;
                } else if (trait == "Summoned" && hero.specialisation == "Barbarian") {
                    resPower += resPower * 0.25;
                } else if (trait == "Holy" && hero.specialisation == "Warlock") {
                    resPower += resPower * 0.25;
                }
            }
        }
        return resPower;
    }
}
