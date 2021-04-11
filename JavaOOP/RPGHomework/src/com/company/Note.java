package com.company;

public class Note extends Item{
    private String text;

    protected Note(String name, String text) {
        super(name);
        this.text = text;
    }
}
