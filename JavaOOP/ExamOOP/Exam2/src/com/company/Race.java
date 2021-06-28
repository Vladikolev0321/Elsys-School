package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Race extends Thread {
    private List<Automobile> automobiles;
    private int countObikolkiToMake;
    private List<Double> pistaOpisanie;


    public Race(List<Automobile> automobiles, int countObikolkiToMake) {
        this.automobiles = automobiles;
        this.countObikolkiToMake = countObikolkiToMake;
        pistaOpisanie = new ArrayList<>();
    }

    public Race(int countObikolkiToMake, List<Double> raceOpisanie) {
        this.countObikolkiToMake = countObikolkiToMake;
        this.pistaOpisanie = raceOpisanie;
    }

    public Race(List<Automobile> automobiles, int countObikolkiToMake, List<Double> raceOpisanie) {
        this.automobiles = automobiles;
        this.countObikolkiToMake = countObikolkiToMake;
        this.pistaOpisanie = raceOpisanie;
    }

    public void addAutomobile(Automobile automobile) throws Exception {
        if(automobile == null){
            throw new Exception("Given car is null");
        }
        automobiles.add(automobile);
    }
    public void changePistaOpisanie(List<Double> newPistaOpisanie, int countObikolkiToMake){
        Collections.copy(pistaOpisanie, newPistaOpisanie);
        this.countObikolkiToMake = countObikolkiToMake;
    }
    public void reset(){
        automobiles.clear();
        countObikolkiToMake = 0;
        pistaOpisanie.clear();
    }
    public void run() {


        automobiles.forEach(c -> c.reset());
        automobiles.forEach(c -> c.start());


//        long start = System.currentTimeMillis();
//// ...
//        long finish = System.currentTimeMillis();
//        long timeElapsed = finish - start;
        for (int i = 0; i < countObikolkiToMake; i++){

            for(var a : automobiles){
                try {
                    a.doALap(pistaOpisanie);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            automobiles.forEach(c -> System.out.println(c));

        }



    }

}
