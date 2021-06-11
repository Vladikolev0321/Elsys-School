package com.company;

import java.util.HashMap;
import java.util.Map;

public class Dish {
    private String name;
    private Map<Product, Integer> products;
    private int timeToCook; // in seconds

    public Dish(String name, HashMap<Product, Integer> products, int timeToCook) {
        this.name = name;
        this.products = products;
        this.timeToCook = timeToCook;
    }
    public double getSalePrice(){
        double price = 0;
        for (var entry : products.entrySet()){
            Product currProduct = entry.getKey();
            price += currProduct.getPrice();
        }
        return price * 2;
    }
}
