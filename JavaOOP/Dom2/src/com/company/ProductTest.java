package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ProductTest {
    private Product product;
    @org.junit.jupiter.api.BeforeEach
    void setUp() {
    }


    @org.junit.jupiter.api.Test
    void getPrice() {
        product = new Product("Qice", "broi", 0.2);
        Assertions.assertEquals(0.2, product.getPrice());
    }
}