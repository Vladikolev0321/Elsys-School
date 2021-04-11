package com.company;

public class Potion extends Item implements Equippable, Consumable{
    private int healthRestored;
    private int manaRestored;
    public Potion(String name, int healthRestored, int manaRestored) {
        super(name);
        this.healthRestored = healthRestored;
        this.manaRestored = manaRestored;
    }

    private int getHealthRestored() {
        return healthRestored;
    }

    private int getManaRestored() {
        return manaRestored;
    }

    @Override////???
    public void consume(Character target) {
        if(target.getCharacterClass().equals("Archer")){
            if(target.getCurrentHealth()+getHealthRestored() <= target.getMaxHealth()){
                target.setCurrentHealth(target.getCurrentHealth()+getHealthRestored());
            }else{
                target.setCurrentHealth(target.getMaxHealth());
            }
        }else if(target.getCharacterClass().equals("Mage")){///what to do to mana
            if(target.getCurrentHealth()+getHealthRestored() <= target.getMaxHealth()){
                target.setCurrentHealth(target.getCurrentHealth()+getHealthRestored());
            }else{
                target.setCurrentHealth(target.getMaxHealth());
            }
            if(((Mage)target).getCurrentMana()+getManaRestored() <= ((Mage)target).getMaxMana()){
                ((Mage)target).setCurrentMana(((Mage)target).getCurrentMana()+getManaRestored());
            }else{
                ((Mage)target).setCurrentMana(((Mage)target).getMaxMana());
            }

        }
    }

}
