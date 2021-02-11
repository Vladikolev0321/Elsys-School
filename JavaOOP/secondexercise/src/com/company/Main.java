package com.company;

public class Main {

    public static void main(String[] args) {
	    Point a = new Point(1, 2);
        Point b = new Point(1, 5);
        Point c = new Point(1, 6);

        Triangle t = new Triangle(a, b, c);

        System.out.println(t.get_perimeter());

        System.out.println(t.get_area());

        Triangle[] triangles = {t};

        Triangle returned = get_biggest_perimeter(triangles);
        Triangle returned1 = get_biggest_area(triangles);
        Triangle returned2 = get_smallest_perimeter(triangles);
        Triangle returned3 = get_smallest_area(triangles);
        System.out.println(returned.get_perimeter());
        System.out.println(returned1.get_perimeter());
        System.out.println(returned2.get_perimeter());
        System.out.println(returned3.get_perimeter());
        

    }
    public static Triangle get_biggest_perimeter(Triangle[] triangles)
    {
        int maxIndex = -1;
        double max = -1;
        for(int i = 0; i < triangles.length; i++)
        {
            if(max < triangles[i].get_perimeter())
            {
                max = triangles[i].get_perimeter();
                maxIndex = i;
            }
        }
        return triangles[maxIndex];
    }
    public static Triangle get_biggest_area(Triangle[] triangles)
    {
        Triangle temp = triangles[0];

        for(int i = 0; i < triangles.length; i++)
        {
            if(temp.get_area() < triangles[i].get_area())
            {
                temp = triangles[i];
            }
        }
        return temp;
    }
    public static Triangle get_smallest_perimeter(Triangle[] triangles)
    {
        Triangle temp = triangles[0];

        for(int i = 0; i < triangles.length; i++)
        {
            if(temp.get_perimeter() > triangles[i].get_perimeter())
            {
                temp = triangles[i];
            }
        }
        return temp;
    }
    public static Triangle get_smallest_area(Triangle[] triangles)
    {
        Triangle temp = triangles[0];

        for(int i = 0; i < triangles.length; i++)
        {
            if(temp.get_area() > triangles[i].get_area())
            {
                temp = triangles[i];
            }
        }
        return temp;
    }
}
