package com.company;

import java.rmi.NotBoundException;

public class Main {

    public static void main(String[] args) {
        Hero myHero = new Hero("Vladi", "Tarikat");
        try{
            myHero.equipItem(new Weapon("Pushka", 20));
            myHero.equipItem(new Weapon("Pushka2", 20));
            myHero.equipItem(new Potion("Potion1"));
            myHero.equipItem(new Potion("Potion1"));
            //myHero.equipItem(new Weapon("Pushka2", 20));
            System.out.println(myHero);
        }
        catch (Exception ex){
            System.out.println(ex.getMessage());
        }

    }
}
