package com.company;

import java.util.List;

public abstract class Shape {
    protected Point center;

    public Shape(Point center) {
        this.center = center;
    }

    public abstract boolean checkCollision(Shape other);

    public abstract List<Point> getPoints();
}