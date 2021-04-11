package com.company;

public class FitnessCard {
    private String number;
    private int countWorkouts;

    public FitnessCard(String number) {
        this.number = number;
        this.countWorkouts = 10;
    }
    public void use(){
        this.countWorkouts--;
    }
}
