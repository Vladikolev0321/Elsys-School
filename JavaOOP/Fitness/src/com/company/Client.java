package com.company;

public class Client {
    protected String firstName;
    protected String lastName;
    protected FitnessCard card;

    public Client(String firstName, String lastName) throws Exception {
        if(firstName.length() == 0){
            throw new Exception("No first name");
        }
        if(lastName.length() == 0){
            throw new Exception("No last name");
        }
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public void setCard(FitnessCard card) {
        this.card = card;
    }
    public FitnessCard getCard() {
        return card;
    }
}
