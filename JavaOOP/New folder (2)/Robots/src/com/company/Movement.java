package com.company;

import java.util.List;

public class Movement extends RobotModule{
    private int speed;
    private String typeMovement;

    public Movement(String type, String serial, int ID, int speed, String typeMovement) {
        super(type, serial, ID);
        this.speed = speed;
        this.typeMovement = typeMovement;
    }

    @Override
    public void processCommand(String command) {
        var splitted = command.split(" ");
        String type = splitted[0];

    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        return false;
    }
}
