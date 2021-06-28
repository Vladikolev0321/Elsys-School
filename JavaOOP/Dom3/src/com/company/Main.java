package com.company;

import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        // Crystal and count of workers in this field
        Map<Crystal, Integer> crystalsField = new HashMap<>();


        for (int i = 0; i < 10; i++){

            Crystal crystal = new Crystal(100);
            crystalsField.put(crystal, 0);

        }
//        Crystal crystal2 = new Crystal(100);
//        Crystal crystal3 = new Crystal(100);
//        Crystal crystal4 = new Crystal(100);
//        Crystal crystal= new Crystal(100);
//        Crystal crystal3 = new Crystal(100);

//
//        crystalsField.put(crystal, 0);
//        crystalsField.put(crystal2, 0);
//        crystalsField.put(crystal3, 0);

        Base base = new Base();
        base.start(crystalsField);
    }
}
