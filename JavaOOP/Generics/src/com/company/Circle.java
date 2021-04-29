package com.company;

public class Circle extends Figure{
    private Point center;
    private int radius;

    public Circle(Point center, int radius) {
        this.center = center;
        this.radius = radius;
    }

    @Override
    protected int get_area() {
        return 2;
    }
}
