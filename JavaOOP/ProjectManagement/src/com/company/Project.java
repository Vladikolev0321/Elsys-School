package com.company;

import java.util.ArrayList;
import java.util.List;

public class Project {
    private List<Epic> epics;

    public Project() {
        this.epics = new ArrayList<>();
    }

    public List<Epic> getEpics() {
        return epics;
    }
}
