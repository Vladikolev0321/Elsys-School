package com.company;

import java.util.List;

public class Head extends RobotModule{
    private List<String> sensors;
    private boolean doesHaveDeepVision;

    public Head(String type, String serial, int ID, List<String> sensors) {
        super(type, serial, ID);
        this.sensors = sensors;

        doesHaveDeepVision = false;
        for(String sensor : sensors){
            if(sensors.lastIndexOf(sensor) != sensors.indexOf(sensor)){
                doesHaveDeepVision = true;
            }
        }

    }

    public List<String> getSensors() {
        return sensors;
    }

    public boolean isDoesHaveDeepVision() {
        return doesHaveDeepVision;
    }

    @Override
    public void processCommand(String command) {

    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        return true;
    }
}
