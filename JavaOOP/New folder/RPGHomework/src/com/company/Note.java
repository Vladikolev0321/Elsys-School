package com.company;

public class Note extends Item{
    private String text;

    public Note(String name, String text) {
        super(name);
        this.text = text;
    }

    @Override
    public String toString() {
        return "Note{" +
                "text='" + text + '\'' +
                '}';
    }
}
