package com.company;

public class Task<T> {
    private T ID;
    private String Name;
    private String Description;
    private Status status;
    private Worker assignee;

    public Task(T ID, String name) {
        this.ID = ID;
        Name = name;
        this.status = Status.Waiting;
    }



}
