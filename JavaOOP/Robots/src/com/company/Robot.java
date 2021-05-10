package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Robot {
    public final String name;
    private String serialNumber;
    private int maxModules;
    private List<RobotModule> modules = new ArrayList<>();


    public Robot(String name, String serialNumber, int maxModules) {
        this.name = name;
        this.serialNumber = serialNumber;
        this.maxModules = maxModules;
    }
    public String getSerialNumber() {
        return serialNumber;
    }

    public List<RobotModule> getModules() {
        return modules;
    }
    public void addModule(RobotModule newModule) throws Exception {
        if(modules.size() >= maxModules){
            throw new Exception("There is no space for this module");
        }
        if(modules.contains(newModule)){
            throw new Exception("There is this module in this colellction");
        }
        modules.add(newModule);
    }
    public boolean isMinimumRequirementCovered(){
        long heads = modules.stream()
                .map((m) -> m.type)
                .filter((m) -> m == "head")
                .count();
        long arms = modules.stream()
                .map((m) -> m.type)
                .filter((m) -> m == "arm")
                .count();
        long legs = modules.stream()
                .map((m) -> m.type)
                .filter((m) -> m == "leg")
                .count();
        if(!(heads >= 1 && arms >= 2 && legs >= 1)){
            return false;
        }
        return modules.stream()
                .map((m) -> m.isMinimumRequirementCovered(
                        modules.stream()
                                .filter((m2) -> m2 != m)
                                .collect(Collectors.toList())
                )
                )
                .allMatch((m) -> m == true);



        return true;
    }
    public void processCommand(String command){

    }
}
