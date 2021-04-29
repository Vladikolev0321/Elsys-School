package com.company;

public class Triangle extends Figure{
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    protected int get_area() {
        return 3;
    }
}
