package com.company;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MonsterTest {

    @org.junit.jupiter.api.Test
    void getPower() {
        Monster testDragon = new Monster(10, 20, "Dragon", Arrays.asList(new String[]{"Evil"}));

        List<Hero> party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Barbarian")});
        assertEquals(200, testDragon.getPower(party));

        party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Knight")});
        assertEquals(250, testDragon.getPower(party));
    }

}