package com.company;

import org.junit.jupiter.params.shadow.com.univocity.parsers.common.processor.core.ColumnOrderDependent;

import java.util.*;
import java.util.stream.Collectors;

public class Restaurant {
    private List<Dish> dishes;
    private List<Chef> chefs;
    private List<Waiter> waiters;
    private Storage storage;
    private double money;
    private Map<Order, Boolean> activeOrders;
    private List<Order> completedOrders;
    private List<Order> failedOrders;

    public Restaurant(List<Dish> dishes, Storage storage, double money) {
        this.dishes = dishes;
        this.storage = storage;
        this.money = money;

        chefs = new ArrayList<>();
        waiters = new ArrayList<>();
        activeOrders = new HashMap<>();
        completedOrders = new ArrayList<>();
        failedOrders = new ArrayList<>();
    }
//    public void cook(){
//
//        /// ?? not sure
//        while ( activeOrders.values().stream().filter(b -> b == true).collect(Collectors.toList()).size() != 0
//                || activeOrders.values().stream().filter(b -> b == false).collect(Collectors.toList()).size() != 0 ){
////            for (Chef chef : chefs) {
////                //chef.start();
////            }
////
////            for (Waiter waiter : waiters) {
////                //waiter.run();
////            }
//        }
//    }


    //check TODO:
    public void addOrder(Order order) throws Exception {
        // check if id == activeOrder, failed, completed
        // check if dish in this order can be served by this restaurant

        if(activeOrders.keySet().stream().anyMatch( o -> o.getId() == order.getId()) || failedOrders.stream().anyMatch( o -> o.getId() == order.getId())
                || completedOrders.stream().anyMatch( o -> o.getId() == order.getId())){
            throw new IllegalArgumentException("The given order's id should be unique");
        }


        for(var orderDish : order.getDishes().entrySet()){
            if(!dishes.stream().anyMatch(d -> d.getName() == orderDish.getKey())){
                throw new Exception("This type of dish in the order can't be made by this restaurant");
            }
        }

        // find the price of the added dish and setting its value
        double sum = 0;
        for (Map.Entry<String, Integer> dishCount : order.getDishes().entrySet()){
            var dishName = dishCount.getKey();
            Dish dish = dishes.stream().filter(d -> d.getName() == dishName).findFirst().orElse(null);
            if(dish != null){
                sum += dish.getSalePrice() * dishCount.getValue();
            }
        }

        order.setFullPrice(sum);
        //

        activeOrders.put(order, true);

    }
    // ???
    public void completeOrder(int id){
        Order currOrder = activeOrders.keySet().stream().filter(o -> o.getId() == id).findFirst()
                .orElseThrow(() -> new IllegalArgumentException("There is no order with such id"));

        //Order currOrder = activeOrders.get(id);
        activeOrders.remove(currOrder);
        System.out.println("Removing order from active with id:" + currOrder.getId());
        completedOrders.add(currOrder);
    }

    public void addChef(Chef chef){ /// check
        Thread thread = new Thread(chef);
        thread.start();
        chefs.add(chef);
    }
    public void addWaiter(Waiter waiter){ //check
        Thread thread = new Thread(waiter);
        thread.start();
        waiters.add(waiter);
    }

    public HashMap<Order, Boolean> getActiveOrders() {
        return (HashMap)activeOrders;
    }

    public List<Dish> getDishes() {
        return dishes;
    }

    public Storage getStorage() {
        return storage;
    }
    public void failOrder(Order order){
        failedOrders.add(order);
        activeOrders.remove(order);
    }

    public void addMoney(double addMoney){
        money += addMoney;
    }
    public void startA(){

    }

    public double getMoney() {
        return money;
    }
}
