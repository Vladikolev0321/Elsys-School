package com.company;

public abstract class Posev {
    private String name;
    private int neededAge;
    private int currentAge;
    protected boolean isObran;
    protected boolean isDead;
    protected boolean isPolqtoThisDay;

    public Posev(String name, int neededAge, int currentAge) {
        this.name = name;
        this.neededAge = neededAge;
        this.currentAge = currentAge;

        isDead = false;
        isObran = false;

    }

    public void setObran(boolean obran) {
        isObran = obran;
    }

    public void setDead(boolean dead) {
        isDead = dead;
    }

    public void setPolqtoThisDay(boolean polqtoThisDay) {
        isPolqtoThisDay = polqtoThisDay;
    }
    public void obirane(){
        isObran = true;
    }

    public int getNeededAge() {
        return neededAge;
    }

    public int getCurrentAge() {
        return currentAge;
    }

    public void setNeededAge(int neededAge) {
        this.neededAge = neededAge;
    }

    public void setCurrentAge(int currentAge) {
        this.currentAge = currentAge;
    }

    public String getName() {
        return name;
    }
}
