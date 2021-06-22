package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class DishTest {
    private Dish dish;
    @BeforeEach
    void setUp() {
    }

    @Test
    void constructorThrowsException() {
        Map<Product, Integer> products = new HashMap<>();
        Product product = new Product("Qice", "broi", 0.2);
        products.put(product, 2);

        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            dish = new Dish("", (HashMap<Product, Integer>) products, 30);
        });
    }
    @Test
    void getSalePriceCalculatesFine() {
        Map<Product, Integer> products = new HashMap<>();
        Product product = new Product("Qice", "broi", 0.2);

        Product product2 = new Product("Kufte", "broi", 0.3);
        products.put(product, 2);
        products.put(product2, 2);

        dish = new Dish("My dish", (HashMap<Product, Integer>) products, 30);

        Assertions.assertEquals(2, dish.getSalePrice());
    }
}