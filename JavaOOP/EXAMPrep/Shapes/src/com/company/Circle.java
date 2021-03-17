package com.company;

import java.util.ArrayList;
import java.util.List;

public class Circle extends Shape{
    private int radius;

    public Circle(Point center, int radius) {
        super(center);
        this.radius = radius;
    }

    @Override
    public boolean checkCollision(Shape other) {
        for(var point : other.getPoints()){
            double distance = Math.sqrt(Math.pow(point.getX()-this.center.getX(), 2) +Math.pow(point.getY()-this.center.getY(), 2));
            if(distance < this.radius)
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public List<Point> getPoints() {

        List<Point> res = new ArrayList<>();

        res.add(new Point(radius*Math.cos(0), radius*Math.sin(0)));
        res.add(new Point(radius*Math.cos(Math.PI/4), radius*Math.sin(Math.PI/4)));
        res.add(new Point(radius*Math.cos(Math.PI/2), radius*Math.sin(Math.PI/2)));
        res.add(new Point(radius*Math.cos(3*Math.PI/4), radius*Math.sin(3*Math.PI/4)));
        res.add(new Point(radius*Math.cos(Math.PI), radius*Math.sin(Math.PI)));
        res.add(new Point(radius*Math.cos(5*Math.PI/4), radius*Math.sin(5*Math.PI/4)));
        res.add(new Point(radius*Math.cos(3*Math.PI/2), radius*Math.sin(3*Math.PI/2)));
        res.add(new Point(radius*Math.cos(7*Math.PI/8), radius*Math.sin(7*Math.PI/8)));

        return res;
    }
}
