package com.company;

import java.util.List;

public class Disease {
    private String name;
    private List<Symptoms> symptoms;

    public Disease(String name, List<Symptoms> symptoms) {
        this.name = name;
        this.symptoms = symptoms;
    }
}
