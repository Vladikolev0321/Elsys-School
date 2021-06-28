package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

    public static void main(String[] args) {
        Map<Integer, Integer> allFibonaccies = new HashMap<>();
        allFibonaccies.put(0, 0);
        allFibonaccies.put(1, 1);


        Scanner scanner = new Scanner(System.in);
        //System.out.println("How much numbers do you want to find fibonnaci?");
        //int countNumbers = scanner.nextInt();
        System.out.println("Enter numbers to find their fibonnaci");


        ExecutorService manager = Executors.newFixedThreadPool(20);



        while(true){
            int number_to_find_fib = scanner.nextInt();
            FibonnaciThread fibonnaciThread = new FibonnaciThread(number_to_find_fib, allFibonaccies);
            manager.submit(fibonnaciThread);
        }


    }
}
