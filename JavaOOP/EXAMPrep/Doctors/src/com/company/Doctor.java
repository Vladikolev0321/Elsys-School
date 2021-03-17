package com.company;

import java.util.List;

public class Doctor {
    private String firstName;
    private String lastName;
    private List<Disease> diseasesKnown;

    public Doctor(String firstName, String lastName, List<Disease> diseasesKnown) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.diseasesKnown = diseasesKnown;
    }
}
