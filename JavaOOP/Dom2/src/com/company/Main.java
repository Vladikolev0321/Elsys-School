package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws Exception {

        //Restaurant restaurant = new Restaurant();
        Product cucumber = new Product("Cucumber", "kg", 2);
        Product tomato = new Product("Tomato", "kg", 3);
        Product cheese = new Product("Cheese", "kg", 4);
        Product potato = new Product("Potato", "kg", 2);


        Map<Product, Integer> potatoes_and_cheeseP = new HashMap<>();
        potatoes_and_cheeseP.put(potato, 2);
        potatoes_and_cheeseP.put(cheese, 2);


        Map<Product, Integer> saladP = new HashMap<>();
        saladP.put(tomato, 2);
        saladP.put(cucumber, 3);
        saladP.put(cheese, 3);

        Dish salad = new Dish("Salad", (HashMap<Product, Integer>) saladP, 2);
        Dish potatoes_and_cheese = new Dish("Potatoes and cheese", (HashMap<Product, Integer>) potatoes_and_cheeseP, 1);


        Storage storage = new Storage();
        storage.addProduct(cucumber, 10);
        storage.addProduct(tomato, 10);
        storage.addProduct(cheese, 10);
        storage.addProduct(potato, 10);

        List<Dish> servedDishesByRestaurant = new ArrayList<>();
        servedDishesByRestaurant.add(salad);
        servedDishesByRestaurant.add(potatoes_and_cheese);

        Restaurant restaurant = new Restaurant(servedDishesByRestaurant, storage, 0);

        HashMap<String, Integer> order1_map = new HashMap<>();
        HashMap<String, Integer> order2_map = new HashMap<>();
        HashMap<String, Integer> order3_map = new HashMap<>();


        order1_map.put(salad.getName(), 1);
        order2_map.put(potatoes_and_cheese.getName(), 1);

        Order order1 = new Order(0, order1_map);
        Order order2 = new Order(1, order2_map);

        restaurant.addOrder(order1);
        restaurant.addOrder(order2);

        Chef chef1 = new Chef("Chef1", restaurant);
        Chef chef2 = new Chef("Chef2", restaurant);

        Waiter waiter = new Waiter("Waiter1", restaurant);
        Waiter waiter2 = new Waiter("Waiter2", restaurant);

        restaurant.addChef(chef1);
        restaurant.addChef(chef2);

        restaurant.addWaiter(waiter);
        restaurant.addWaiter(waiter2);


        Thread.sleep(8000);
        System.out.println("Final restaurant money: " + restaurant.getMoney());


    }
}
