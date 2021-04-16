package com.company;

import java.util.ArrayList;
import java.util.List;

public abstract class Character {
    private int currentHealth;
    private int maxHealth;
    private int intelligence;
    private int dextirity;
    private List<Item> Inventar;
    private List<Equippable> Hotbar;
    private int inventarCapacity;
    private int hotbarCapacity;

    protected Character(int currentHealth, int maxHealth, int intelligence, int dextirity) {
        if(currentHealth < 0){throw new IllegalArgumentException("Health shouldn't be negative");}
        if(maxHealth < 0){throw new IllegalArgumentException("MaxHealth shouldn't be negative");}
        if(intelligence < 0){throw new IllegalArgumentException("Intelligence shouldn't be negative");}
        if(dextirity < 0){throw new IllegalArgumentException("Dextirity shouldn't be negative");}

        this.currentHealth = currentHealth;
        this.maxHealth = maxHealth;
        this.intelligence = intelligence;
        this.dextirity = dextirity;
        this.Inventar = new ArrayList<>();
        this.Hotbar = new ArrayList<>();
        this.inventarCapacity = 10;
        this.hotbarCapacity = 3;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public void setCurrentHealth(int currentHealth) {
        this.currentHealth = currentHealth;
    }

    public int getCurrentHealth() {
        return currentHealth;
    }

    public int getMaxHealth() {
        return maxHealth;
    }

    public int getDextirity() {
        return dextirity;
    }

    protected abstract String getCharacterClass();

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Current class:" + getCharacterClass()+"\n");
        sb.append("Current health:" + getCurrentHealth());
        return sb.toString();
    }
    public void pick(Item newItem) throws Exception {///CHECK
        if(Inventar.size() < inventarCapacity){
            Inventar.add(newItem);
            if(newItem instanceof Equippable && Hotbar.size() < hotbarCapacity) {
                Hotbar.add((Equippable) newItem);
            }
        }else{
            throw new Exception("There are no slots for this item");
        }
    }
    public void useAt(int index, Character target) throws Exception {
        if(index < 0 || index >= Hotbar.size())
        {
            throw new IndexOutOfBoundsException("Given index is out of bounds");
        }
        if(Hotbar.get(index) instanceof Consumable){
            //System.out.println(this.getCharacterClass()+" consumed:" + Hotbar.get(index).getName());
            ((Consumable) Hotbar.get(index)).consume(this);
            for(var item : Inventar){
                if(Hotbar.get(index) == item){
                    Inventar.remove(item);
                    break;
                }
            }
            Hotbar.remove(index);
        }else if(Hotbar.get(index) instanceof Usable){
            ((Usable)Hotbar.get(index)).use(this, target);
            for(var item : Inventar){
                if(Hotbar.get(index) == item){
                    Inventar.remove(item);
                    break;
                }
            }
            Hotbar.remove(index);
        }else{
            throw new Exception("This item isn't consumable or usable");
        }
    }
    public void printInventar(){
        for (int i = 0; i < Inventar.size(); i++){
            System.out.println(Inventar.get(i).getName());
        }
    }
    public void printHotbar(){
        for (int i = 0; i < Hotbar.size(); i++){
            System.out.println(Hotbar.get(i));
        }
    }

}
