package com.company;

import java.util.ArrayList;
import java.util.List;

public class Epic<T> {
    private T ID;
    private String Name;
    private String Description;
    private Status status;
    private List<Story> stories;

    public Epic(T ID, String name) {
        this.ID = ID;
        Name = name;
        this.status = Status.Waiting;
        stories = new ArrayList<>();
    }

    public List<Story> getStories() {
        return stories;
    }
}
