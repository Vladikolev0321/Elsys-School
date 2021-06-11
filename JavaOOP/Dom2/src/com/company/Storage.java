package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Storage {
    private Map<Product, Integer> products;

    public Storage(){
        products = new HashMap();
    }
    // check if works
    public void addProduct(Product product, int amount){
        if(products.containsKey(product)){
            products.put(product, products.get(product) + amount);
        }else{
            products.put(product, amount);
        }
    }
    public void getProduct(Product product, int amount) throws Exception {
        if(!products.containsKey(product)){
            throw new Exception("There isn't such product in the storage");
        }
        if(products.containsKey(product) && products.get(product) >= amount){
            products.put(product, products.get(product) - amount);
        }else if(products.containsKey(product) && products.get(product) < amount){
            throw new Exception("There isn't the wanted amount in the storage");
        }
    }
}
