package com.company;

import java.util.List;

public class Record {
    private Patient patient;
    private List<Visits> visits;

    public Record(Patient patient, List<Visits> visits) {
        this.patient = patient;
        this.visits = visits;
    }
    public void AddVisit(Visits visit){
        visits.add(visit);
    }

}
