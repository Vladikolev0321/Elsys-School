package com.company;

import static java.lang.Math.abs;

public class Rectangle implements IFiqure {

    private Point p1;
    private Point p2;

    public Rectangle(Point p1, Point p2){
        this.p1 = p1;
        this.p2 = p2;
    }
    @Override
    public double get_perimeter() {
        double a = Math.abs(p1.x - p2.x);
        double b = Math.abs(p1.y - p2.y);
        return 2 * (a+b);
    }

    @Override
    public double get_area() {
        double a = Math.abs(p1.x - p2.x);
        double b = Math.abs(p1.y - p2.y);
        return a*b;
    }
}
