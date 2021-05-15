package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WizardTest {

    @BeforeEach
    void setUp() {

    }

    @Test
    void getPower() {
        Wizard wizard = new Wizard(4, 2, 6, "Sorcerer");
        Monster testDragon = new Monster(10, 20, "Dragon", Arrays.asList(new String[]{ "Evil"}));

        List<Hero> party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Barbarian")});

        Assertions.assertEquals(30, wizard.getPower(party, testDragon));
    }
}