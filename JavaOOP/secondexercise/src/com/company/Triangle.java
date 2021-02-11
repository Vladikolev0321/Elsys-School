package com.company;

public class Triangle {
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public double get_distance(Point x, Point y)
    {
        return Math.sqrt(Math.pow(y.get_x() - x.get_x(), 2) + Math.pow(y.get_y() - x.get_y(), 2));
    }
    public double get_perimeter()
    {
        double firstSide = get_distance(a, b);
        double secondSide = get_distance(a, c);
        double thirdSide = get_distance(b, c);

        return firstSide + secondSide + thirdSide;
    }
    public double get_area()
    {
        double firstSide = get_distance(a, b);
        double secondSide = get_distance(a, c);
        double thirdSide = get_distance(b, c);
        double p = this.get_perimeter();

        return Math.sqrt(p*(p-firstSide)*(p-secondSide)*(p-thirdSide));
    }






}
