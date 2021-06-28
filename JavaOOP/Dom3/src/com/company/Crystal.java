package com.company;

import java.util.concurrent.Semaphore;

public class Crystal {
    private int currCrystals;
    private Semaphore semaphore;


    public Crystal(int currCrystals) {
        this.currCrystals = currCrystals;
    }

    public synchronized int mine(int wantedCrystals){
        int finalCrystals = 0;
        if(currCrystals >= wantedCrystals){
            currCrystals -= wantedCrystals;
            finalCrystals = wantedCrystals;
        }else {
            currCrystals = 0;
            finalCrystals = currCrystals;
        }

        return finalCrystals;
    }

    public int getCurrCrystals() {
        return currCrystals;
    }

    public synchronized void setCurrCrystals(int currCrystals) {
        this.currCrystals = currCrystals;
    }
}
