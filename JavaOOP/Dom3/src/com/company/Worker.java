package com.company;

public class Worker implements Runnable{
    private String id; ///
    private int countCrystalsTaken;

    public Worker(String id) {
        this.id = id;
        this.countCrystalsTaken = 0;
    }

    @Override
    public void run() {

    }

    public int getCountCrystalsTaken() {
        return countCrystalsTaken;
    }
}
