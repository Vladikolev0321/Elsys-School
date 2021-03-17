package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PowerDataTest {
    PowerData powerData;
    @BeforeEach
    void setUp() {
        powerData = new PowerData(0, 0, 0);
    }

    @AfterEach
    void tearDown() {

    }

    @Test
    void getAllData(){
        Assertions.assertEquals(0, powerData.minimalPower);
        Assertions.assertEquals(0, powerData.maximalPower);
        Assertions.assertEquals(0, powerData.typicalPower);

    }


}