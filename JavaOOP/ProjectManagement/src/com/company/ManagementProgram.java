package com.company;

import java.util.ArrayList;
import java.util.List;

public class ManagementProgram {
    private List<Worker> workers;
    private List<Project> projects;

    private ManagementProgram(){
        projects = new ArrayList<>();
    }

    public List<Story> getAllStories(Status status){
        List<Story> toReturnStories = new ArrayList<>();

        for (var project : projects){
            for (var epic : project.getEpics()){
                for (var story : epic.getStories()){
                    if(story.getStatus().equals(status)){
                        toReturnStories.add(story)
                    }
                }
            }
        }
        return toReturnStories;
    }
    public <T> List<Story> getAllStories(Status status, T epicId){
        List<Story> toReturnStories = new ArrayList<>();

        for (var project : projects){
            for (var epic : project.getEpics()){
                for (var story : epic.getStories()){
                    if(story )){
                        toReturnStories.add(story)
                    }
                }
            }
        }
    }
}
