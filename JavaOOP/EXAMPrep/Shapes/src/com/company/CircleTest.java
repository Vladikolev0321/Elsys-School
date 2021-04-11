package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CircleTest {

    Circle circle;
    @BeforeEach
    void setUp() {
        circle = new Circle(new Point(2, 3), 2);
    }

    @Test
    void checkCollision() {
        Assertions.assertEquals(true, circle.checkCollision(circle));
    }

    @Test
    void getPoints() {
    }
}