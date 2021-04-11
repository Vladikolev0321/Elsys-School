package com.company;

import java.util.List;
import java.util.Random;

public class RegisterEmployee extends Worker{
    public RegisterEmployee(String firstName, String lastName, int salary) {
        super(firstName, lastName, salary);
    }

    public void register(List<FitnessCard> cards, List<Client> clients, Client client){
        Random random = new Random();
        int index = random.nextInt(cards.size() - 0)+0;
        FitnessCard card = cards.get(index);
        cards.remove(card);
        clients.add(client);
    }
}
