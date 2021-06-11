package com.company;

import java.util.ArrayList;
import java.util.List;

public class Restaurant {
    private List<Dish> dishes;
    private List<Chef> chefs;
    private List<Waiter> waiters;
    private Storage storage;
    private double money;
    private List<Order> activeOrders;
    private List<Order> completedOrders;
    private List<Order> failedOrders;

    public Restaurant(List<Dish> dishes, Storage storage, double money) {
        this.dishes = dishes;
        this.storage = storage;
        this.money = money;

        chefs = new ArrayList<>();
        waiters = new ArrayList<>();
        activeOrders = new ArrayList<>();
        completedOrders = new ArrayList<>();
        failedOrders = new ArrayList<>();
    }
}
