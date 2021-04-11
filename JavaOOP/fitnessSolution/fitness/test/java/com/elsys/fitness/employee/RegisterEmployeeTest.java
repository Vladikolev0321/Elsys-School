package com.elsys.fitness.employee;

import com.elsys.fitness.Fitness;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RegisterEmployeeTest {
    private RegisterEmployee registerEmployee;
    @BeforeEach
    void setUp() {
        registerEmployee =  new RegisterEmployee("asd", "asd", new Fitness(1, ""));
    }

    @Test
    void registerCustomer() {

    }
}