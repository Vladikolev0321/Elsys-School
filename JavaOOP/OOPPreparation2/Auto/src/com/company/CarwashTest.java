package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Assertions;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CarwashTest {

    Carwash carwash;
    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        carwash = new Carwash(1, 4, 20);
    }

    @org.junit.jupiter.api.Test
    void addService() throws Exception {
        List<Service> servicesForFirstOrder = new ArrayList<>();
        servicesForFirstOrder.add(new Service("Wash", 20));
        Assertions.assertThrows(Exception.class, () ->{

            carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
            carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
            carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
            carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
            carwash.addOrder(1, new Automobile("BMW", "X5", "car"), servicesForFirstOrder);
                }
        );
    }

    @org.junit.jupiter.api.Test
    void addOrder() {
    }

    @org.junit.jupiter.api.Test
    void completeOrder() {
    }

    @org.junit.jupiter.api.Test
    void getOverview() {
    }
}