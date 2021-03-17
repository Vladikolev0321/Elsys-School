package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ComputerTest {
    Computer computer;
    @BeforeEach
    void setUp() {
        List<IPart> temp = new ArrayList<>();
        temp.add(new MotherBoard("am1"));
        //temp.add(new MotherBoard("am1"));

        computer = new Computer(temp);
    }

    @Test
    void getConsumption() throws Exception{
        Assertions.assertThrows(Exception.class, () ->{
            computer.getConsumption();
        });
    }
}