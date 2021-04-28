package com.company;

public class Worker<T> {
    private T ID;
    private String firstName;
    private String lastname;
    private WorkerType position;

    public Worker(T ID, String firstName, String lastname, WorkerType position) {
        this.ID = ID;
        this.firstName = firstName;
        this.lastname = lastname;
        this.position = position;
    }
}
