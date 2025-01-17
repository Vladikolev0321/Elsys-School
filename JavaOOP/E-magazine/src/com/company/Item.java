package com.company;

public class Item {
    private int ID;
    private String name;
    private double price;
    private MetricUnit metricunit;

    public Item(int ID, String name, double price, MetricUnit metricunit) {
        this.ID = ID;
        this.name = name;
        this.price = price;
        this.metricunit = metricunit;
    }

    public int getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public MetricUnit getMetricunit() {
        return metricunit;
    }
}
