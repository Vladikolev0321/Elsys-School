package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
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
    public void addOrder(int id, Automobile automobile, List<Service> services) throws Exception {
        if(slots <= activeOrders.size()){
            throw new Exception("The carwash slots are full");
        }
        activeOrders.add(new Order(id, automobile, services));
    }
    public void completeOrder(int id){
       // Order completedOrder = activeOrders.stream().filter(o -> o.getId() == id).limit(1);

        Order completedOrder = null;
        for (var o : new ArrayList<>(activeOrders)){
            if(o.getId() == id){
                completedOrder = o;
            }
        }
        activeOrders.remove(completedOrder);
        completedOrders.add(completedOrder);

        double price = 0;
        for (var s : completedOrder.getServices()){
            price += s.getPrice();
        }
        price += price * completedOrder.getAutomobile().getPriceMultiplier();

        cash += price;
    }
    public String getOverview(){
        StringBuilder sb = new StringBuilder();
//        for(var o : completedOrders){
//            for(var service : o.getServices()){
//                sb.append(service.getName());
//
//               // sb.append(" "+ )
//            }
//        }
        for (var s : services){
            sb.append(s.getName());
//            long count = completedOrders.stream().filter(o ->
//                            o.getServices().stream()
//                            .anyMatch(s2 -> s2.getName() == s.getName())).count();

            var AllServicesWithThisName  = completedOrders.stream().map(o ->
                    o.getServices())
                    .map(s1 -> s1.stream().filter(s3 -> s3.getName() == s.getName()).collect(Collectors.toList())).collect(Collectors.toList());

            int rCount = 0;
            for (var l : AllServicesWithThisName){
                rCount += l.size();
            }
            sb.append(" "+ rCount  + "\n");


            Map<Automobile, Integer> automobilesWithThisService = new HashMap<>();
            for (var o : completedOrders){
                int countCar = 0;
                for (var serv : o.getServices()){
                    if(serv.getName() == s.getName()){
                        automobilesWithThisService.put(o.getAutomobile(), 0);
                        countCar++;
                    }
                }
                automobilesWithThisService.put(o.getAutomobile(), countCar);
            }

            for (var kvp : automobilesWithThisService.entrySet()){
                sb.append(" - " + kvp.getKey().getType() + Integer.toString(kvp.getValue()) + "\n");
            }

            //var allCarsWithThisService = completedOrders.stream().filter(o -> o.)
        }
        return sb.toString().trim();
    }

}
