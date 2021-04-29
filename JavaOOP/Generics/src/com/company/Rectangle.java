package com.company;

public class Rectangle extends Figure{
    private Point lowerLeft;
    private Point upperRight;

    public Rectangle(Point lowerLeft, Point upperRight) {
        this.lowerLeft = lowerLeft;
        this.upperRight = upperRight;
    }

    @Override
    protected int get_area() {
        return 1;
    }
}
