package com.company;

import java.util.HashMap;
import java.util.Map;

public class Order {
    private int id;
    private Map<String, Integer> dishes;
    private double fullPrice;

    public Order(int id, HashMap<String, Integer> dishes) {
        this.id = id;
        this.dishes = dishes;
        this.fullPrice = 0;
    }

    public int getId() {
        return id;
    }

    public Map<String, Integer> getDishes() {
        return dishes;
    }

    public double getFullPrice() {
        return fullPrice;
    }

    public void setFullPrice(double fullPrice) {
        this.fullPrice = fullPrice;
    }
}
