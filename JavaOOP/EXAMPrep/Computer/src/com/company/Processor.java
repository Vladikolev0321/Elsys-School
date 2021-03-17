package com.company;

public class Processor implements IPart{
    private int countCores;
    private int frequency;

    public Processor(int countCores, int frequency) {
        this.countCores = countCores;
        this.frequency = frequency;
    }

    @Override
    public PowerData getConsumption() {
        double typicalPow = countCores * frequency*frequency / 2 * 0.5;
        double minPow = typicalPow * 0.25;
        double maxPow = typicalPow * 5;

        return new PowerData(minPow, maxPow, typicalPow);
    }
}
