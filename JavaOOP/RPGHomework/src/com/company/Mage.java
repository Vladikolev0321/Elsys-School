package com.company;

public class Mage extends Character{
    private int currentMana;
    private int maxMana;

    public Mage() {
        super(60, 60, 10, 5);///IS it harcoded
        this.currentMana = 80;
        this.maxMana = 80;
    }

    public void setCurrentMana(int currentMana) {
        this.currentMana = currentMana;
    }

    public int getCurrentMana() {
        return currentMana;
    }

    public int getMaxMana() {
        return maxMana;
    }

    @Override
    protected String getCharacterClass() {
        return "Mage";
    }

    @Override
    public String toString() {
        return  "Current Class:" + getCharacterClass() + "\n"+
                "currentHealth=" + getCurrentHealth()+ "\n"+
                "currentMana=" + getCurrentMana();
    }
}
