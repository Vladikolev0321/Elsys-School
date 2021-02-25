package com.company;

import java.util.ArrayList;

public class Bag extends Items {
    ArrayList<Items> bag;
    int capacity;

    public Bag(String name){
        super(name);
        bag = new ArrayList<>();
        capacity = 6;
    }
    public void addToBag(Items item) throws Exception{
        if(bag.toArray().length < capacity){
            bag.add(item);
        }
        else{
            throw new Exception("No space in the bag");
        }
    }

    @Override
    public String toString() {
        return "Bag{" +
                "bag=" + bag +
                ", capacity=" + capacity +
                '}';
    }

}
