package com.company;

public class Crystal {
    private int currCrystals;

    public Crystal(int currCrystals) {
        this.currCrystals = currCrystals;
    }

    public int mine(int wantedCrystals){
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
}
