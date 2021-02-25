package com.company;

import java.rmi.NotBoundException;
import java.util.ArrayList;

public class Hero {
    private String name;
    private String clas;
    private ArrayList<Items> equip;

    private ArrayList<Items> bag;

    public Hero(String name, String clas){
        this.name = name;
        this.clas = clas;
        equip = new ArrayList<>();
        bag = new ArrayList<>();
    }


    private int getCountWeapons(){
        int count = 0;
        for (int i = 0; i < equip.toArray().length; i++){
            if(equip.toArray()[i] instanceof  Weapon){
                count++;
            }
        }
        return count;
    }



    private int getCountPotions(){
        int count = 0;
        for (int i = 0; i < equip.toArray().length; i++){
            if(equip.toArray()[i] instanceof  Potion){
                count++;
            }
        }
        return count;
    }
    private int getCountArmour(){
        int count = 0;
        for (int i = 0; i < equip.toArray().length; i++){
            if(equip.toArray()[i] instanceof  Armour){
                count++;
            }
        }
        return count;
    }
    public void equipItem(Items item) throws Exception {
        if(item instanceof Weapon){
            if(getCountWeapons() < 2){
                equip.add(item);
            }
            else{
                throw new Exception("No space");
            }
        }
        else if(item instanceof Potion){
            if(getCountPotions() < 4){
                equip.add(item);
            }
            else{
                throw new Exception("No space");
            }
        }
        else if(item instanceof Armour){
            if(getCountArmour() < 6){
                equip.add(item);
            }
            else{
                throw new Exception("No space");
            }
        }

    }
    public void pickUpItem(Items item) throws Exception {
        if(bag.toArray().length < 6)
        {
            bag.add(item);
        }
        else{
            throw new Exception("No space");
        }
    }


    @Override
    public String toString() {
        return "Hero{" +
                "name='" + name + '\'' +
                ", clas='" + clas + '\'' +
                ", equip=" + equip +
                ", bag=" + bag +
                '}';
    }

}
