package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ComputerTest {
    Computer computer;
    List<IPart> temp;
    @BeforeEach
    void setUp() {
         temp = new ArrayList<>();
         temp.add(new MotherBoard("am1"));

        computer = new Computer(temp);
    }

    @Test
    void getConsumption() throws Exception{
        Assertions.assertEquals(25, computer.getConsumption().getMinPower());
        Assertions.assertEquals(25, computer.getConsumption().getMaxPower());
        Assertions.assertEquals(25, computer.getConsumption().getTypicalPower());


        assertThrows(Exception.class, () ->{
            temp.add(new MotherBoard("am1"));

            computer = new Computer(temp);
            computer.getConsumption();
        });

    }
}