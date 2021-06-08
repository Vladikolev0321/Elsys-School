package com.company;

public class Task {
    private int id;
    private int points;
    private Difficulty difficulty;
    private double coef;
    public static int counter = 1;

    public int getId() {
        return id;
    }

    public Task(int id, int points, Difficulty difficulty) {
        this.id = counter;
        if(points > 0){
            throw new IllegalArgumentException("Point shouldn't be negative");
        }
        this.points = points;
        this.difficulty = difficulty;
        switch (difficulty){
            case LOW : this.coef = 0.5;
                break;
            case MEDIUM: this.coef = 1;
                break;
            case HIGH: this.coef = 1.5;
                break;
        }
        counter++;

    }

    public int getPoints() {
        return points;
    }

    public Difficulty getDifficulty() {
        return difficulty;
    }

    public double getCoef() {
        return coef;
    }
}
