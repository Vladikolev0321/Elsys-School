package com.company;

import java.util.List;

public class Triangle extends Shape{
    private List<Point> points;


    public Triangle(Point center, List<Point> points) {
        super(center);
        this.points = points;
    }

    @Override
    public boolean checkCollision(Shape other) {
        return false;
    }

    @Override
    public List<Point> getPoints() {
        return
    }
}
