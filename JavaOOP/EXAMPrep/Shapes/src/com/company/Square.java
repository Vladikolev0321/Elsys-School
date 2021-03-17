package com.company;

import java.util.ArrayList;
import java.util.List;

public class Square extends Shape{
    private int d;


    public Square(Point center, int d) {
        super(center);
        this.d = d;
    }

    @Override
    public boolean checkCollision(Shape other) {
        for(var point : other.getPoints()){
            if(this.center.getX() - d <= point.getX() &&  point.getX() <= this.center.getX() + d
                    && this.center.getY() - d <= point.getY() &&  point.getY() <= this.center.getY() + d)
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public List<Point> getPoints() {
        List<Point> res = new ArrayList<>();
        res.add(new Point(center.getX()+d/2, center.getY()+d/2));
        res.add(new Point(center.getX()+d/2, center.getY()-d/2));
        res.add(new Point(center.getX()-d/2, center.getY()+d/2));
        res.add(new Point(center.getX()-d/2, center.getY()-d/2));

        return res;
    }
}
