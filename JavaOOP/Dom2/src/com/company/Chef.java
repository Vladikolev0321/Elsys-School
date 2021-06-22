package com.company;

import org.junit.experimental.max.CouldNotReadCoreException;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Chef implements Runnable{
    private String name;
    private Restaurant restaurant;

    public Chef(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {

        while (true){
            Order order = null;
            synchronized (this) {
                order = getActiveOrder();
                if (order == null) {
                    break;
                }
                try {
                    System.out.println("Cooking order with id:" + order.getId());
                    cook(order);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

            }

        //}
        System.out.println(this.name + " finished working");
    }


    public void cook(Order order) throws Exception {
        // iterate over order's dishes hash map
        //Order order = getActiveOrder();
        if(order == null){
            return;
        }
        for (Map.Entry<String, Integer> dishkvp : order.getDishes().entrySet()){

            // checking if count of current dishes in order is 0
            while(dishkvp.getValue() > 0){
                Dish currDish = restaurant.getDishes().stream().filter(d -> d.getName().equals(dishkvp.getKey())).findFirst().orElse(null);
                if(currDish != null){
                    // iterating over products in
                    for(Map.Entry<Product, Integer> productKvp : currDish.getProducts().entrySet()){
//                        if(productKvp.getValue() * dishkvp.getValue() > restaurant.getStorage().getProduct()){
//
//                        }else{
                            try {
                                restaurant.getStorage().getProduct(productKvp.getKey(), productKvp.getValue());
                            }catch (Exception ex){
                                System.out.println(ex.getMessage());
                                restaurant.failOrder(order);
                                throw new Exception("Failed this order");
                            }

                    }

                    try{
                        Thread.sleep(currDish.getTimeToCook() * 1000);
                    }catch (InterruptedException ex){
                        System.out.println(ex.getMessage());
                    }

                    dishkvp.setValue(dishkvp.getValue() - 1);
                }

            }
            System.out.println("Order with id:" + order.getId() + " is cooked");
//            for(var ord : restaurant.getActiveOrders().entrySet()){
//                System.out.println(ord.getKey().getId() + " " + ord.getValue());
//            }

        }


    }

    public Order getActiveOrder(){
        Order order = null;

//        for(var ord : restaurant.getActiveOrders().entrySet()){
//                System.out.println(ord.getKey().getId() + " " + ord.getValue());
//            }

        if(restaurant.getActiveOrders().values().stream().filter(v -> v == true).collect(Collectors.toList()).size() > 0){
            for(var o : restaurant.getActiveOrders().entrySet()){
                // Order Boolean

                if(o.getValue() == true){

                    o.setValue(false);
                    return o.getKey();
                   // order = o.getKey();
                }
            }
        }
        return null;

    }
//    @Override
//    public void run() {
//
//    }
}
