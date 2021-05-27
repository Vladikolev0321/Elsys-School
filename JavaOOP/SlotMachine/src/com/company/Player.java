package com.company;

public class Player {
    private String name;
    private double startCash;

    public Player(String name, double startCash) {
        this.name = name;
        this.startCash = startCash;
    }

    public String getName() {
        return name;
    }

    public double getStartCash() {
        return startCash;
    }

    public void setStartCash(double startCash) {
        this.startCash = startCash;
    }
}
