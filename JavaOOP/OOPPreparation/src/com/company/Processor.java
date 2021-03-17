package com.company;

public class Processor implements  IPart{
    private int coreCount;
    private double coreFrequency;

    public int getCoreCount() {
        return coreCount;
    }

    public double getCoreFrequency() {
        return coreFrequency;
    }

    public Processor(int coreCount, double coreFrequency) {
        this.coreCount = coreCount;
        this.coreFrequency = coreFrequency;
    }

    @Override
    public PowerData getConsumption() {
        double typical = coreCount * Math.pow(coreFrequency, 2) / 2 * 0.5;
        double minPower = typical * 0.25;
        double maxPower = typical * 5;

        return new PowerData(minPower, maxPower, typical);
    }
}
