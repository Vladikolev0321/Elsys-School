package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
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

        System.out.println(res);
    }
}
