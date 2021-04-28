package com.company;

import java.util.ArrayList;
import java.util.List;

public class  Story<T>{
    private T ID;
    private String Name;
    private String Description;
    private Status status;
    private int points;
    private Worker assignee;
    private List<Task> tasks;

    public Story(T ID, String name) {
        this.ID = ID;
        Name = name;
        this.status = Status.Waiting;
        tasks = new ArrayList<>();
    }

    public Status getStatus() {
        return status;
    }

    public T getID() {
        return ID;
    }
}
