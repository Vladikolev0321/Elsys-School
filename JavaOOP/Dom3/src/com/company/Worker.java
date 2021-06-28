package com.company;

import java.util.Map;

public class Worker implements Runnable{
    private int id; ///
    private int countCrystalsTaken;
    private Map<Crystal, Integer> crystalFields;
    private Base base;

    public Worker(int id, Map<Crystal, Integer> crystalFields, Base base) {
        this.id = id;
        this.countCrystalsTaken = 0;
        this.crystalFields = crystalFields;
        this.base = base;
    }

    @Override
    public void run() {
        System.out.println("Worker:" + id + " starts working");

        while(!crystalFields.isEmpty()){
            // finds first free block
            Map.Entry<Crystal, Integer> firstFreeCrystalBlock = crystalFields.entrySet().stream().filter(c -> c.getValue() < 2 && c.getKey().getCurrCrystals() > 0).findFirst().orElse(null);
            Crystal freeBlockKey = null;
            if(firstFreeCrystalBlock == null){
                continue;
            }
            //System.out.println("Worker:" + id + " walks");
            /// sleeps for 1 second
            try {
                Thread.sleep(1000);
            }catch (InterruptedException ex){
                ex.printStackTrace();
            }

            if (firstFreeCrystalBlock.getValue() == 2){ // if crystal field is busy
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                firstFreeCrystalBlock = crystalFields.entrySet().stream().filter(c -> c.getValue() < 2 && c.getKey().getCurrCrystals() > 0).findFirst().orElse(null);
                if(firstFreeCrystalBlock != null){
                    firstFreeCrystalBlock.setValue(firstFreeCrystalBlock.getValue() + 1);
                    freeBlockKey = firstFreeCrystalBlock.getKey(); ////?????
                }else{
                    continue;//
                }
                // continue;
            }else{ //if found block is not busy
                firstFreeCrystalBlock.setValue(firstFreeCrystalBlock.getValue() + 1);
                freeBlockKey = firstFreeCrystalBlock.getKey();

                // get blocks
//                try {
//                    Thread.sleep(1500);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                countCrystalsTaken = freeBlockKey.mine(20);
//
//                firstFreeCrystalBlock.setValue(firstFreeCrystalBlock.getValue() - 1);
//
//                if(freeBlockKey.getCurrCrystals() == 0){
//                    crystalFields.remove(freeBlockKey);
//                }

            }

            //System.out.println(freeBlockKey.getCurrCrystals());
            // should it be outside the else ??
            // getting the crystals from the field
            try {
                Thread.sleep(1500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Worker:" + id + " is mining");
            countCrystalsTaken = freeBlockKey.mine(20);

            if(countCrystalsTaken > 0){

                firstFreeCrystalBlock.setValue(firstFreeCrystalBlock.getValue() - 1);

                if(freeBlockKey.getCurrCrystals() == 0){
                    crystalFields.remove(freeBlockKey);
                }

                System.out.println("Worker:" + id + " got " + this.countCrystalsTaken + " crystals");

                // going to the base
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                // adding taken crystals to base
                System.out.println("Worker:" + id + " took to base " + this.countCrystalsTaken + " crystals");
                base.addCrystal(this.countCrystalsTaken);
                countCrystalsTaken = 0;

                System.out.println("Worker:" + id + " is resting after work");
                // rest after work
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }


        }


        System.out.println("Worker:" + id + " stopped working");
    }

    public int getCountCrystalsTaken() {
        return countCrystalsTaken;
    }

}
