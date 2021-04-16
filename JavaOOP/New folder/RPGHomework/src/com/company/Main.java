package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
            Archer archer = new Archer();
            System.out.println(archer.toString());
            Mage mage = new Mage();
            System.out.println(mage.toString());

            Note note = new Note("Note1", "This is the first note");
            Potion potion = new Potion("Potion1", 20, 20);
            Scroll scroll = new Scroll("Scroll1", 20);
            Sword sword = new Sword("Sword1", 10);

            //archer.pick();
            System.out.println("Picking items");
            try{
                archer.pick(potion);
                archer.pick(scroll);
                archer.pick(sword);
                archer.pick(note);
                mage.pick(potion);
                mage.pick(scroll);
                mage.pick(sword);
                mage.pick(note);
            }catch (Exception ex){
                System.out.println(ex.getMessage());
            }
            System.out.println("Archer's inventar:");
            archer.printInventar();
            System.out.println("Archer's hotbar:");
            archer.printHotbar();
            System.out.println();
            System.out.println("Mage's inventar:");
            mage.printInventar();
            System.out.println("Mage's hotbar:");
            mage.printHotbar();

            System.out.println();
            System.out.println("Before fight:");
            System.out.println(archer.toString());
            System.out.println(mage.toString());
            System.out.println();

            System.out.println("Starting Fight");

            try {

                System.out.println("Archer uses scroll on mage");
                archer.useAt(1, mage);
                System.out.println(mage.toString());

                System.out.println("Mage uses scroll on archer");
                mage.useAt(1, archer);
                System.out.println(archer.toString());

                System.out.println("Archer uses 1 potion");
                archer.useAt(0, archer);
               // archer.useAt(0, archer);
                System.out.println(archer.toString());

            }catch (Exception ex){
                System.out.println(ex.getMessage());
            }
            System.out.println();
            System.out.println("After fight:");
            System.out.println(archer.toString());
            System.out.println(mage.toString());
            //archer.printHotbar();
            //mage.printHotbar();
            //archer.printInventar();
            //mage.printInventar();








    }
}
