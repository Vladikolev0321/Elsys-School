package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MotherBoardTest {

    MotherBoard motherBoard;
    @BeforeEach
    void setUp() {
        motherBoard = new MotherBoard("am2");
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void getConsumption() {
        Assertions.assertEquals(35, motherBoard.getConsumption().getMinPower());
        Assertions.assertEquals(35, motherBoard.getConsumption().getMaxPower());
        Assertions.assertEquals(35, motherBoard.getConsumption().getTypicalPower());

    }
}