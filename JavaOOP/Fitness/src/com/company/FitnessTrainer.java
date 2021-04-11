package com.company;

public class FitnessTrainer extends Worker{

    public FitnessTrainer(String firstName, String lastName, int salary) {
        super(firstName, lastName, salary);
    }

    public void train(Workout workout, Client client) throws Exception {
        if(!workout.getType().equals("Fitness workout")){
            throw new Exception("Invalid workout type");
        }
        client.getCard().use();

    }

}
