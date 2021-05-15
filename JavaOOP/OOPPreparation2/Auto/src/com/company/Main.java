package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {
	    Carwash carwash = new Carwash(1, 4, 20);

	    carwash.addService(new Service("Wash", 20));
        carwash.addService(new Service("Clean", 30));

        List<Service> servicesForFirstOrder = new ArrayList<>();
        servicesForFirstOrder.add(new Service("Wash", 20));
        carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
        List<Service> servicesForFirstOrder2 = new ArrayList<>();
        servicesForFirstOrder2.add(new Service("Clean", 20));
        carwash.addOrder(1, new Automobile("Audi", "X5", "SUV"), servicesForFirstOrder2);

        carwash.completeOrder(1);

        System.out.println(carwash.getOverview());

    }
}
