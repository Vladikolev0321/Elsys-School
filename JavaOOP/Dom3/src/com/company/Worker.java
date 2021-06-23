package com.company;

public class Worker implements Runnable{
    private String id;
    private int countCrystalsTaken;

    public Worker(String id, int countCrystalsTaken) {
        this.id = id;
        this.countCrystalsTaken = countCrystalsTaken;
    }

    @Override
    public void run() {

    }
}
