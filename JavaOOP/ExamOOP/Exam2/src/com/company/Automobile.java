package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Automobile extends Thread{
    private int curr_pos = 1;
    private String name;
    private int nomerOfCurrObikolka;
    private List<Double> timeForEverySegment;
    private List<Double> timeForEveryObikolka;


    public Automobile(int curr_pos, String name, int nomerOfCurrObikolka, int countSegments) {
        this.curr_pos = curr_pos;
        this.name = name;
        this.nomerOfCurrObikolka = nomerOfCurrObikolka;
        timeForEverySegment = new ArrayList<>();
        timeForEveryObikolka = new ArrayList<>();

        for (int i = 0; i < countSegments; i++){
            timeForEveryObikolka.add(null);
        }

    }
    public void reset(){
        this.curr_pos = 1;
        name = new String();
        nomerOfCurrObikolka = 0;
        timeForEverySegment.clear();
        timeForEveryObikolka.clear();
    }

    @Override
    public String toString() {
        return "Automobile{" +
                "curr_pos=" + curr_pos +
                ", name='" + name + '\'' +
                ", nomerOfCurrObikolka=" + nomerOfCurrObikolka +
                ", timeForEverySegment=" + timeForEverySegment +
                ", timeForEveryObikolka=" + timeForEveryObikolka +
                '}';
    }

    public void doALap(List<Double> pistaOpisanie) throws InterruptedException {
        synchronized (this){
            Random random = new Random();
            int i = 0;
            double timeForFullObikolka = 0;
            for (var segment : pistaOpisanie){
                var rand = 0.75 + (1.25 - 0.75) * random.nextDouble();
                double speedForThisSegment = segment * rand;
                double timeForThisSegment = 1 / speedForThisSegment;
                //timeForEverySegment
                try {
                    Thread.sleep((int)timeForThisSegment * 1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                timeForEverySegment.set(i, timeForThisSegment);
                i++;
                timeForFullObikolka += timeForThisSegment;
            }
            //int time = (int)timeForFullObikolka;
            timeForEveryObikolka.add(timeForFullObikolka);

        }


    }

}
