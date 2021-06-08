package com.company;

public class Student implements Runnable{
    private String name;
    private int nomer;

    public Student(String name, int nomer) {
        this.name = name;
        this.nomer = nomer;
    }
    public synchronized void solveTask(Task task) throws InterruptedException {
        double timeNeeded = task.getPoints()*1000*task.getCoef();
        Thread.sleep((long)timeNeeded);
    }

    @Override
    public void run() {

    }
}
