package com.company;

public class Address {
    private Country country;
    private String city;
    private String street;
    private String numberOfApartment;

    public Address(Country country, String city, String street, String numberOfApartment) {
        this.country = country;
        this.city = city;
        this.street = street;
        this.numberOfApartment = numberOfApartment;
    }


}
