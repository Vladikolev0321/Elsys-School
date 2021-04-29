package com.company;

import java.util.ArrayList;
import java.util.List;

public class Container<T extends Figure> {
    private List<T> figures;

    public Container(){
        figures = new ArrayList<>();
    }

    public void add(T figure){
        figures.add(figure);
    }
    public T get(int index){
        return figures.get(index);
    }
    public List<T> getAllByArea(int area){
        List<T> toReturn = new ArrayList<>();
        for(var f : figures){
            if(f.get_area() == area){
                toReturn.add(f);
            }
        }
        return toReturn;
    }
    public int getTotalArea(){
        int sum = 0;
        for(var f : figures){
            sum += f.get_area();
        }
        return sum;
    }
    public void getAllContaining(Point p){

    }
    public T getBiggest(){
        T max = null;
        int maxArea = 0;
        for(var f : figures){
            if(f.get_area() > maxArea){
                max = f;
                maxArea = f.get_area();
            }
        }
        return max;
    }
    public T getSmallest(){
        T min = null;
        int minValue = figures.get(0).get_area();
        for(var f : figures){
            if(f.get_area() < minValue){
                min = f;
                minValue = f.get_area();
            }
        }
        return min;
    }
    public void orderDescending(){
        for (int i = 0; i < figures.size()-1; i++){
            for (int j = i + 1; j < figures.size(); j++){
                if(figures.get(i).get_area() > figures.get(j).get_area()){
                    T temp = figures.get(i);
                    T temp2 = figures.get(j);
                    figures.set(j, temp);
                    figures.set(j, temp2);
                }
            }
        }
    }


}
