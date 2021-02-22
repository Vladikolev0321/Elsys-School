package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        /*
        int res = Integer.parseInt(args[0]);
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        ArrayList<Character> symbols = new ArrayList<Character>();


        res = Integer.parseInt(args[0]);


        for(int i = 1; i < args.length; i+=2){
            String symbol = args[i];
            int secNum = Integer.parseInt(args[i+1]);


            System.out.println(symbol);
            System.out.println(secNum);

            if(symbol.equals("+")){
                res += secNum;
            }
            else if(symbol.equals("/")){
                res /= secNum;
            }
            else if(symbol.equals("*")){
                res *=  secNum;
            }
            else if(symbol.equals("-")){
                res -= secNum;
            }
        }
        */

         ArrayList<Double> numbers = new ArrayList<Double>();
         ArrayList<Character> symbols = new ArrayList<Character>();

         for(int i = 0; i < args.length; i++)
         {
             if(i % 2 == 0) {
                 numbers.add(Double.parseDouble(args[i]));
             }
             else {
                 symbols.add(args[i].charAt(0));
             }
         }
    /// iterate over all symbols
        //
         while(!symbols.isEmpty())
         {
             if(symbols.contains('*')){
                 for(int i = 0; i < symbols.size(); i++){
                     if(symbols.get(i) == '*'){
                         double res = numbers.get(i) * numbers.get(i+1);
                         numbers.set(i, res);
                         numbers.remove(i+1);
                         symbols.remove(i);
                         i = 0;
                     }
                 }
             }
             if(symbols.contains('/')){
                 for(int i = 0; i < symbols.size(); i++){
                     if(symbols.get(i) == '/'){
                         double res = numbers.get(i) / numbers.get(i+1);
                         numbers.set(i, res);
                         numbers.remove(i+1);
                         symbols.remove(i);
                         i = 0;
                     }
                 }
             }
             if(symbols.contains('+')){
                 for(int i = 0; i < symbols.size(); i++){
                     if(symbols.get(i) == '+'){
                         double res = numbers.get(i) + numbers.get(i+1);
                         numbers.set(i, res);
                         numbers.remove(i+1);
                         symbols.remove(i);
                         i = 0;
                     }
                 }
             }
             if(symbols.contains('-')){
                 for(int i = 0; i < symbols.size(); i++){
                     if(symbols.get(i) == '-'){
                         double res = numbers.get(i) - numbers.get(i+1);
                         numbers.set(i, res);
                         numbers.remove(i+1);
                         symbols.remove(i);
                         i = 0;
                     }
                 }
             }
         }

         System.out.println(numbers.get(0));



    }
}
