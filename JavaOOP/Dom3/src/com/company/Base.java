package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Base {
    private int currCrystals;
    private List<Worker> workers;
    private ExecutorService manager = Executors.newFixedThreadPool(20);


    public Base(ArrayList<Worker> workers) {
        this.currCrystals = 0;
        this.workers = workers;
    }
    public void addWorker(Worker worker){
        if(worker != null){
            workers.add(worker);
        }else{
            throw new IllegalArgumentException("Worker can't be null")
        }
    }

    public void createWorker(Worker worker){
        //Worker worker = new Worker();

        manager.submit(worker);

    }
}
