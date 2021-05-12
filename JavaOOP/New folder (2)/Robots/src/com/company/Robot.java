package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Robot {
    private List<RobotModule> modules;
    private String name;
    private String serial;
    private int maxCountModules;

    public Robot(String name, String serial, int maxCountModules) {
        this.name = name;
        this.serial = serial;
        this.modules = new ArrayList<>();
        this.maxCountModules = maxCountModules;
    }
    public void addModule(RobotModule newModule) throws Exception {
        if(modules.contains(newModule)){
            throw new Exception("There is such module in modules");
        }
        if(modules.size() >= maxCountModules){
            throw new Exception("The capacity is full");
        }

        this.modules.add(newModule);
    }
    public boolean isMinimumRequirementCovered(){
        long countHead = modules.stream()
                .map((m) -> m.getType())
                .filter((m) -> m == "head")
                .count();

        long countArms = modules.stream()
                .map((m) -> m.getType())
                .filter((m) -> m == "arm")
                .count();

        long countLegs = modules.stream()
                .map((m) -> m.getType())
                .filter((m) -> m == "leg")
                .count();

        if(!(countHead >= 1 && countArms >= 2 && countLegs >= 1)){
            return false;
        }

        return modules.stream()
                .map((m) -> m.isMinimumRequirementCovered(
                        modules.stream()
                            .filter((m2) -> m2 != m)
                            .collect(Collectors.toList())
                ))
                .allMatch((m) -> m == true);
    }
    void processCommand(String command){
        var splitted = command.split(" ");
        String type = splitted[0];

        for (var m : modules){
            if(m.getType() == type){
                m.processCommand(splitted[1]+splitted[2]);
            }
        }

    }



}
