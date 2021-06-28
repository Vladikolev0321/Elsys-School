package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.ReentrantLock;

public class Base {
    private int currCrystals;
    private List<Worker> workers;
    private ExecutorService manager = Executors.newFixedThreadPool(20);


    public Base() {
        this.currCrystals = 0;
        this.workers = new ArrayList<>();
    }
    public void addWorker(Worker worker){
        if(worker != null){
            workers.add(worker);
        }else{
            throw new IllegalArgumentException("Worker can't be null");
        }
    }

    public void createWorker(Worker worker){
        //Worker worker = new Worker();
        workers.add(worker);
        manager.submit(worker);

    }
    public void start(Map<Crystal, Integer> crystalFields) throws InterruptedException {
        while(workers.size() < 20){
            //System.out.println("Workers count:" + workers.size());
            if(workers.size() == 0){
                Worker firstW = new Worker(1, crystalFields, this);
                createWorker(firstW);
            }
            //System.out.println("in");

            //System.out.print(currCrystals + " ");
            synchronized (workers){
                if(currCrystals > 50){
                    //   System.out.println("Creating \n\n\n\n");
                    currCrystals -= 50;
                    Worker worker = new Worker(workers.size()+1, crystalFields, this);
                    createWorker(worker);

                }
            }

        }

        manager.shutdown();
        Thread.sleep(5000);
        System.out.println("Game ended");
        System.out.println("Base has " + currCrystals + " crystals");
    }

    public synchronized void addCrystal(int toAddCrystal){
        currCrystals += toAddCrystal;
    }
}
