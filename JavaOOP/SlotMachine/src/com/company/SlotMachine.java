package com.company;

import java.util.Random;

public class SlotMachine implements Runnable{
    private Player currPlayer;
    private Thread t = new Thread();
    private int cashToGiveToCasino;
    private int cashToRemoveFromCasino;


    public SlotMachine(Player currPlayer) {
        this.currPlayer = currPlayer;
        this.cashToGiveToCasino = 0;
        this.cashToRemoveFromCasino = 0;
    }

    @Override
    public void run() {
        try{
            while(currPlayer.getStartCash() >= 10){
                synchronized (this){
                    currPlayer.setStartCash(currPlayer.getStartCash()-10);
                    Random random = new Random();
                    int res = random.nextInt(1 - (-2) + 1) + (-2);
                    if(res == 1){
                        currPlayer.setStartCash(currPlayer.getStartCash() + 30);
                        cashToRemoveFromCasino += 10 * 3;
                    }else{
                        cashToGiveToCasino += 10;
                    }
                    Thread.sleep(10000);
                }
            }

            System.out.println();
        }catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }
}
