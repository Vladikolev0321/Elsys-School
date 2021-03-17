package com.company;

public class HardDrive implements IPart{
    private double speed;
    private double capacity;


    public HardDrive(double speed, double capacity) {
        this.speed = speed;
        this.capacity = capacity;
    }

    @Override
    public PowerData getConsumption() {
        double typical = speed * capacity / 160000;
        double minPower = typical * 0.1;
        double maxPower = typical * 2;

        return new PowerData(minPower, maxPower, typical);
    }
}
