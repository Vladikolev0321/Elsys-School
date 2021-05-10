package com.company;

import java.util.List;

public class RobotHead extends RobotModule{
    public final List<String> sensors;
    private boolean hasDeepVision;
    private int rotation;

    public RobotHead(String serial, String id, List<String> sensors) {
        super("head", serial, id);
        this.sensors = sensors;
        // TODO: implement with stream
        this.hasDeepVision = false;

        for(String sensor : sensors){
            if(sensors.lastIndexOf(sensor) != sensors.indexOf(sensor)){
                this.hasDeepVision = true;
            }
        }
    }

    @Override
    public void processCommand(String command) {
        // rotate_left 30
        // rotate_right 30
        String[] attr = command.split(" ");

        switch (attr[0]){
            case "rotate_left":
                System.out.println("Rotate left " + attr[1]);
                rotation -= Integer.parseInt(attr[1]);
                break;
            case "rotate_right":
                System.out.println("Rotate right " + attr[1]);
                rotation += Integer.parseInt(attr[1]);
                break;
        }


    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        return false;
    }
}
