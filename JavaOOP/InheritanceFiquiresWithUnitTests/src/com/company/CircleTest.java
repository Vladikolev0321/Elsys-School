package com.company;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CircleTest {
    private Circle circle;

    @BeforeEach
    void setUp() throws Exception{
        circle = new Circle(new Point(2, 3), 2);
    }

    @Test
    void testGetPerimeter() {
        assertEquals(2*Math.PI*2, circle.get_perimeter());
    }

    @Test
    void testGetArea() {
        assertEquals(Math.PI*2*2, circle.get_area());
    }

    @Test
    void testIfThrows() throws Exception {
        assertThrows(Exception.class, () ->{
            circle = new Circle(new Point(2, 3), -1);
                });
    }
}