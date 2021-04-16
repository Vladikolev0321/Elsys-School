package com.company;

import java.util.Map;

public class Order {
    private int ID;
    private int userId;
    private Address adressForDelivery;
    private Status status;
    private Map<Item, Integer> items;


    public Order(int ID, int userId, Address adressForDelivery, Status status, Map<Item, Integer> items) {
        this.ID = ID;
        this.userId = userId;
        this.adressForDelivery = adressForDelivery;
        this.status = status;
        this.items = items;
    }

}
