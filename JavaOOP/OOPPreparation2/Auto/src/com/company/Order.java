package com.company;

import java.util.List;
import java.util.Random;

public class Order {
    private int id;
    private Automobile automobile;
    private List<Service> services;

    public Order(int id, Automobile automobile, List<Service> services) {
        this.id = id;
        this.automobile = automobile;
        this.services = services;
    }
    public Order(Automobile automobile, List<Service> services) {
        Random random = new Random();
        this.id = random.nextInt();
        this.automobile = automobile;
        this.services = services;
    }

    public int getId() {
        return id;
    }

    public Automobile getAutomobile() {
        return automobile;
    }

    public List<Service> getServices() {
        return services;
    }
}
