package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;

import static org.junit.jupiter.api.Assertions.*;

class SquareTest {

    Square square;
    @BeforeEach
    void setUp() {
        square = new Square(new Point(10, 5), 3);
    }

    @org.junit.jupiter.api.Test
    void checkCollisionTest() {
        Assertions.assertEquals(true, square.checkCollision(square));
    }
}