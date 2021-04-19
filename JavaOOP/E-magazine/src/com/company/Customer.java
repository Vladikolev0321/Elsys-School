package com.company;

public class Customer {
    private int ID;
    private String firstName;
    private String lastName;
    private Address adress;

    public Customer(int ID, String firstName, String lastName, Address adress) {
        this.ID = ID;
        this.firstName = firstName;
        this.lastName = lastName;
        this.adress = adress;
    }

    public int getID() {
        return ID;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public Address getAdress() {
        return adress;
    }
}
