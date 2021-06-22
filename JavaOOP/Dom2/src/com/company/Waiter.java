package com.company;

import java.sql.SQLOutput;
import java.util.Map;

public class Waiter implements Runnable{
    private String name;
    private Restaurant restaurant;

    public Waiter(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {

        while(true){
            //System.out.println(restaurant.getActiveOrders().size());

                if(restaurant.getActiveOrders().size() <= 0){
                    break;
                }

                takeOrder();

            //System.out.println(restaurant.getActiveOrders().size());
        }

        System.out.println("Waiter finished working");

    }

    private synchronized void takeOrder(){
        for(Map.Entry<Order, Boolean> orderIsFinished : restaurant.getActiveOrders().entrySet()){
            if(orderIsFinished.getValue() == false){
                Order currOrder = orderIsFinished.getKey();

                if(currOrder.getDishes().entrySet().stream().allMatch(kvp -> kvp.getValue() == 0)){
                    System.out.println("Order is taken with price:" + currOrder.getFullPrice());
                    restaurant.addMoney(currOrder.getFullPrice());
                    restaurant.completeOrder(currOrder.getId());
                    System.out.println("Order" + currOrder.getId() + " is completed");
                    return;

                }
            }
        }
    }
}
