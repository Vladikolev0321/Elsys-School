package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StorageTest {
    private Storage storage;
    @BeforeEach
    void setUp() {
        storage = new Storage();
    }

    @Test
    void getProductThrowsExceptions() throws Exception {
        Product product = new Product("Qice", "broi", 0.2);
        Product product2 = new Product("Kufte", "broi", 0.7);
        storage.addProduct(product, 2);
        Assertions.assertThrows(Exception.class, () -> {
            storage.getProduct(product2, 2);
        });

        Assertions.assertThrows(Exception.class, () -> {
            storage.getProduct(product, 3);
        });

    }

}