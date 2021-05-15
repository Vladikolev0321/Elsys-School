package com.company;

public class Automobile {
    private String maker;
    private String model;
    private double priceMultiplier;
    private String type;

    public Automobile(String maker, String model, String type) {
        this.maker = maker;
        this.model = model;
        this.type = type;
        if(type == "car"){
            priceMultiplier = 1;
        }else if(type == "SUV"){
            priceMultiplier = 1.5;
        }else{
            priceMultiplier = 2;
        }
    }

    public double getPriceMultiplier() {
        return priceMultiplier;
    }

    public String getType() {
        return type;
    }
}
