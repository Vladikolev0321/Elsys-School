package com.company;

import java.util.ArrayList;
import java.util.List;

public class Rectangle extends Shape{
    private int d1;
    private int d2;

    public Rectangle(Point center, int d1, int d2) {
        super(center);
        this.d1 = d1;
        this.d2 = d2;
    }

    @Override
    public boolean checkCollision(Shape other) {
        for(var point : other.getPoints()){
            if(this.center.getX() - d1 <= point.getX() &&  point.getX() <= this.center.getX() + d1
                    && this.center.getY() - d2 <= point.getY() &&  point.getY() <= this.center.getY() + d2)
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public List<Point> getPoints() {
        List<Point> res = new ArrayList<>();
        res.add(new Point(center.getX()+d1/2, center.getY()+d1/2));
        res.add(new Point(center.getX()+d1/2, center.getY()-d1/2));
        res.add(new Point(center.getX()-d1/2, center.getY()+d1/2));
        res.add(new Point(center.getX()-d1/2, center.getY()-d1/2));

        return res;
    }
}
