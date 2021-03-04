package com.company;

public class Circle implements IFiqure{

    private Point p1;
    private int radius;

    public Circle(Point p1, int radius) throws Exception{
        this.p1 = p1;
        if(radius <= 0){
            throw new Exception("Radius cannot be 0 or lower");
        }
        this.radius = radius;

    }

    @Override
    public double get_perimeter() {
        return 2 * Math.PI * this.radius;
    }

    @Override
    public double get_area() {
        return Math.PI * this.radius * this.radius;
    }
}
