package com.company;

public class PowerData {
    private final double minPower;
    private final double maxPower;
    private final double typicalPower;

    public PowerData(double minPower, double maxPower, double typicalPower) {
        this.minPower = minPower;
        this.maxPower = maxPower;
        this.typicalPower = typicalPower;
    }

    public double getMinPower() {
        return minPower;
    }

    public double getMaxPower() {
        return maxPower;
    }

    public double getTypicalPower() {
        return typicalPower;
    }
}
