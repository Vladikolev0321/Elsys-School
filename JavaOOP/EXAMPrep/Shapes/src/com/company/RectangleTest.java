package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RectangleTest {

    Rectangle rectangle;
    @BeforeEach
    void setUp() {
        rectangle = new Rectangle(new Point(2, 3), 3, 3);
    }

    @Test
    void checkCollision() {
        Assertions.assertEquals(true, rectangle.checkCollision(rectangle));

    }

    @Test
    void getPoints() {
    }
}