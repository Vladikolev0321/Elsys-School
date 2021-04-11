package com.company;

import java.util.List;

public class GroupTrainer extends Worker{

    public GroupTrainer(String firstName, String lastName, int salary) {
        super(firstName, lastName, salary);
    }

    public void train(Workout workout, List<Client> clients) throws Exception {
        if(clients.size() < 3){
            throw new Exception("Cant have less than 3 people in a group training");
        }
        for(Client client : clients){
            client.getCard().use();
        }
    }
}
