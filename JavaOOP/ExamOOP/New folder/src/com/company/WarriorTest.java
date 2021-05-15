package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WarriorTest {

    @BeforeEach
    void setUp() {
    }

    @Test
    void getPower() {
        Warrior warrior;

        warrior = new Warrior(4, 6, 6, "Barbarian");
        Monster testDragon = new Monster(10, 20, "Dragon", Arrays.asList(new String[]{ "Evil"}));

        List<Hero> party;
        party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Barbarian")});

        Assertions.assertEquals(24, warrior.getPower(party, testDragon));


     /*  Warrior warrior2 = new Warrior(4, 6, 6, "Knight");

        List<Hero> party2 = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Cleric")});
        Monster testDragon = new Monster(10, 20, "Dragon", Arrays.asList(new String[]{ "Evil"}));

        Assertions.assertEquals(30, warrior2.getPower(party2, testDragon));
*/

    }

}