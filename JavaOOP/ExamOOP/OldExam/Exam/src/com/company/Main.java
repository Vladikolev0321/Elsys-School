package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        Farmer farmer = new Farmer("Vladi");
        int countPosevs = scan.nextInt();
        for(int i = 0; i < countPosevs; i++){
            String posevName = scan.next();
            String posevClass = scan.next();
          //  var attr = posev.split(" ");

            Posev pos = null;
            if(posevClass.equals("Vegetable")){
                pos = new Vegetable(posevName, 0);
            }else if(posevClass.equals("Fruit")){
                pos = new Fruit(posevName, 0);
            }else if(posevClass.equals("Cactus")){
                pos = new Cactus(posevName, 0);
            }///fix here
            farmer.addPosev(pos);
        }
        int countInstruments = scan.nextInt();
        for(int i = 0; i < countInstruments; i++){
            farmer.addInstrument(scan.next());
        }
        int countDaysWillWork = scan.nextInt();
        farmer.minavanePrezPosevi(countDaysWillWork);
        farmer.getInfo();
        scan.close();
    }


}
