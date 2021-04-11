package com.company;

import java.util.ArrayList;
import java.util.Arrays;
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
    public Disease diagnose(Patient client, Symptoms[] symptoms)throws Exception{
        if(Arrays.asList(symptoms).contains(Symptoms.температура) && Arrays.asList(symptoms).contains(Symptoms.Кашлица) && Arrays.asList(symptoms).contains(Symptoms.затрудненодишане)){
            List<Symptoms> symptoms1 = new ArrayList<>();
            symptoms1.add(Symptoms.Кашлица);symptoms1.add(Symptoms.температура);symptoms1.add(Symptoms.затрудненодишане);

            Disease disease =  new Disease("Covid 19", symptoms1);
            if(!this.diseasesKnown.contains(disease)) {

                throw new Exception("The doctor doesnt know this disease");
            }
        }
        else{
            throw new Exception("There is not such disease with this symptoms");
        }
    }
}
