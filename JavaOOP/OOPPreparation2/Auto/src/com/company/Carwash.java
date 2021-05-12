package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Carwash {
    private int id;
    private int slots;
    private double cash;
    private List<Service> services;
    private List<Order> activeOrders;
    private List<Order> completedOrders;

    public Carwash(int id, int slots, double cash) {
        this.id = id;
        this.slots = slots;
        this.cash = cash;
        services = new ArrayList<>();
        activeOrders = new ArrayList<>();
        completedOrders = new ArrayList<>();
    }

    public void addService(Service service){
        services.add(service);
    }
    public void addOrder(Automobile automobile, List<Service> services) throws Exception {
        if(slots >= activeOrders.size()){
            throw new Exception("The carwash slots are full");
        }
        activeOrders.add(new Order(automobile, services));
    }
    public void completeOrder(int id){
        Order completedOrder = (Order) activeOrders.stream().filter(o -> o.getId() == id).limit(1);

        activeOrders.remove(completedOrder);
        completedOrders.add(completedOrder);

        double price = 0;
        for (var s : completedOrder.getServices()){
            price += s.getPrice();
        }
        price += price * completedOrder.getAutomobile().getPriceMultiplier();

        cash += price;
    }

}
