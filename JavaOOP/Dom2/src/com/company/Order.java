package com.company;

import java.util.HashMap;
import java.util.Map;

public class Order {
    private int id;
    private Map<String, Integer> dishes;

    public Order(int id, HashMap<String, Integer> dishes) {
        this.id = id;
        this.dishes = dishes;
    }
}
