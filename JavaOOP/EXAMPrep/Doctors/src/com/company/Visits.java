package com.company;

import java.util.List;

public class Visits {
    private String data;
    private List<Symptoms> symptoms;
    private String diagnosedDisease;

    public Visits(String data, List<Symptoms> symptoms, String diagnosedDisease) {
        this.data = data;
        this.symptoms = symptoms;
        this.diagnosedDisease = diagnosedDisease;
    }
}
