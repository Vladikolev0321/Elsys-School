package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {

    public static void main(String[] args) throws Exception {

        FitnessCard card1 = new FitnessCard("3443");
        FitnessCard card2 = new FitnessCard("2333");
        FitnessCard card3 = new FitnessCard("1234");


        Client client1 = new Client("Vanio", "Petrov");
        Client client2 = new Client("Ivan", "Petrov");
        Client client3 = new Client("ivanka", "Petrova");
        RegisterEmployee registerEmployee = new RegisterEmployee("Joro", "Ignatov", 500);
        FitnessTrainer fitnessTrainer1 = new FitnessTrainer("Valio", "Jekov", 600);
        FitnessTrainer fitnessTrainer2 = new FitnessTrainer("Mario", "Petrov", 600);
        GroupTrainer groupTrainer1 = new GroupTrainer("Stefan", "Ivanov", 900);
        GroupTrainer groupTrainer2 = new GroupTrainer("Jeko", "Stoqnov", 800);

        List<FitnessCard> cards = new ArrayList<>();
        cards.add(card1);
        cards.add(card2);
        cards.add(card3);

        List<Client> clients = new ArrayList<>();
        clients.add(client1);
        clients.add(client2);

        List<FitnessTrainer> fitnessTrainers = new ArrayList<>();
        fitnessTrainers.add(fitnessTrainer1);
        fitnessTrainers.add(fitnessTrainer2);

        List<GroupTrainer> groupTrainers = new ArrayList<>();
        groupTrainers.add(groupTrainer1);
        groupTrainers.add(groupTrainer2);

        registerEmployee.register(cards, clients, client1);
        registerEmployee.register(cards, clients, client2);

        train(fitnessTrainers, groupTrainers, clients, new Workout("Train", "Fitness workout"));
        train(fitnessTrainers, groupTrainers, clients, new Workout("Train", "Group workout"));



    }
    public static int getRandomNumberUsingNextInt(int min, int max) {
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }
    public static void train(List<FitnessTrainer> fitnessTrainers,List<GroupTrainer> groupTrainers,List<Client> clients, Workout workout) throws Exception {
        int rand;
        if(workout.getType() == "Fitness workout"){
            rand = getRandomNumberUsingNextInt(0, fitnessTrainers.size());
            fitnessTrainers.get(rand).train(workout, clients.get(0));
        }
        if(workout.getType() == "Group workout"){
            rand = getRandomNumberUsingNextInt(0, groupTrainers.size());
            groupTrainers.get(rand).train(workout, clients);
        }
    }
}
