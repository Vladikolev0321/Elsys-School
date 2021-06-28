package com.company;

import java.util.Map;

public class FibonnaciThread implements Runnable{
    private int number;
    private Map<Integer, Integer> allfibonaccies;

    public FibonnaciThread(int number, Map<Integer, Integer> allfibonaccies) {
        this.number = number;
        this.allfibonaccies = allfibonaccies;
    }

    @Override
    public void run() {
                calculate();
    }

    private  void calculate(){
        for (int i = 0; i < number; i++){
            // if the map of all fibbonacies doesn't contains it adds it
            synchronized (allfibonaccies){
            if(!allfibonaccies.containsKey(i)){
                // synchronising the adding of fibbonacies
                    allfibonaccies.put(i, allfibonaccies.get(i-1)+allfibonaccies.get(i-2));
                }

            }
            if(i+1 == number){
                System.out.println("Fibonacci of " + number + " is " + allfibonaccies.get(number-1));
                break;
            }
        }
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
