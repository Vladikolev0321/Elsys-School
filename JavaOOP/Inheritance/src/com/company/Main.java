package com.company;

import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        List<Object> myList = new LinkedList<>();
        myList.iterator();

        Ruler myRuler = new Ruler("Kim Chen", 44);

        System.out.println(myRuler.canTravel());

        List<ICommunist> voters = new LinkedList<>();
        voters.add(myRuler);

        for(ICommunist voter:voters){
            voter.vote();
        }


    }
}
