package com.company;

public class HardDrive implements IPart{
    private int speed;
    private int capacity;

    public HardDrive(int speed, int capacity) {
        this.speed = speed;
        this.capacity = capacity;
    }


    @Override
    public PowerData getConsumption() {
        double typicalPow = speed * capacity / 160000;
        double minPow = typicalPow * 0.1;
        double maxPow = typicalPow * 2;

        return new PowerData(minPow, maxPow, typicalPow);
    }
}
