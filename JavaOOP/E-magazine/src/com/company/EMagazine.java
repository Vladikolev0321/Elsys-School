package com.company;

import java.util.*;

public class EMagazine {

    private Country country;
    private List<Country> countryList;
    private Map<Item, Integer> allItems;
    private Map<Item, Integer> koshnica;
    private Set<Customer> customers;
    private Customer currCustomer;
    private Set<Order> orders;


    public EMagazine(Country country, List<Country> countryList, Customer currCustomer) {
        this.country = country;
        this.countryList = countryList;
        allItems = new HashMap<>();
        this.koshnica = new HashMap<>();
        customers = new HashSet<>();
        currCustomer = currCustomer;
        orders = new HashSet<>();
    }

    public void registerCustomer(Customer customer){
        Random random = new Random();
        int currCustomerId = random.nextInt(100);
        Customer newCustomer = new Customer(currCustomerId, customer.getFirstName(), customer.getLastName(), customer.getAdress());

        customers.add(newCustomer);
    }
    public void addItem(Item item, int amount){
        Random random = new Random();
        int newItemId = random.nextInt(100);
        Item newItem = new Item(newItemId, item.getName(), item.getPrice(), item.getMetricunit());
        allItems.put(newItem, amount);
    }
    public void removeItem(Item item, int amount){
        if(item == null){ throw new IllegalArgumentException("Item given cannot be null");}
        boolean isItem = false;
        for(var kvp : allItems.entrySet()){
            if(kvp.getKey() == item){
                isItem = true;
                if(amount > kvp.getValue()){
                    throw new IllegalArgumentException("Cannot remove more amount that is current");
                }
                kvp.setValue(kvp.getValue()-amount);
            }
        }
        if(!isItem){
            throw new IllegalArgumentException("There is not such item");
        }
    }
    public void addItemToCart(int ID, int amount){
        for(var kvp : allItems.entrySet()){
            if(kvp.getKey().getID() == ID){
                //kvp.setValue(kvp.getValue()-amount);
                koshnica.put(kvp.getKey(), amount);
            }
        }
    }
    public void checkoutCart() throws Exception {
        if(koshnica.size() == 0){
            throw new Exception("The cart is empty, cannot checkout");
        }
        for(var kvp : allItems.entrySet()){
            if(koshnica.containsKey(kvp.getKey())){
                if(koshnica.get(kvp.getKey()) > kvp.getValue()){
                    throw new Exception("There is not enough amount of this product");
                }
                kvp.setValue(kvp.getValue()-koshnica.get(kvp.getKey()));
                //koshnica.put(kvp.getKey(), amount);

                Random random = new Random();
                int orderId = random.nextInt(100);
                Order order = new Order(orderId, currCustomer.getID(), currCustomer.getAdress(), Status.Open, koshnica);

            }
        }
    }
    public void shipOrder(int ID){
        boolean isOrder = false;
        for (var order : orders){
            if(order.getID() == ID){
                isOrder = true;
                if(!countryList.contains(order.getAdressForDelivery().getCountry())){
                    order.setStatus(Status.Failed);
                    throw new IllegalArgumentException("This country isn't in the countryList");
                }
                order.setStatus(Status.Shipped);
            }
        }
        if(!isOrder){
            throw new IllegalArgumentException("There isn't order with such ID");
        }
    }
    public void completeOrder(int ID){
        boolean isOrder = false;
        for (var order : orders){
            if(order.getID() == ID){
                isOrder = true;
                order.setStatus(Status.Completed);
            }
        }
        if(!isOrder){
            throw new IllegalArgumentException("There isn't order with such ID");
        }
    }
    public void failOrder(int ID){
        boolean isOrder = false;
        for (var order : orders){
            if(order.getID() == ID){
                isOrder = true;
                order.setStatus(Status.Failed);
            }
        }
        if(!isOrder){
            throw new IllegalArgumentException("There isn't order with such ID");
        }
    }






}
