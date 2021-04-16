package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EMagazine {

    private Country country;
    private List<Country> countryList;
    private Map<Item, Integer> allItems;
    private Map<Item, Integer> koshnica;
    private List<Customer> customers;


    public EMagazine(Country country, List<Country> countryList, Map<Item, Integer> allItems, Map<Item, Integer> koshnica, List<Customer> customers) {
        this.country = country;
        this.countryList = countryList;
        this.allItems = allItems;
        this.koshnica = koshnica;
        this.customers = customers;
    }

    public void registerCustomer(Customer customer){
        Customer customer1 = new Customer(customer.ID, customer.firstName, c);

    }



}
