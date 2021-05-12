package com.company;

import java.util.List;

public abstract class RobotModule {
    private String type;
    private String serial;
    private int ID;

    public RobotModule(String type, String serial, int ID) {
        this.type = type;
        this.serial = serial;
        this.ID = ID;
    }

    public String getType() {
        return type;
    }

    public String getSerial() {
        return serial;
    }

    public int getID() {
        return ID;
    }

    public abstract void processCommand(String command);
    public abstract boolean isMinimumRequirementCovered(List<RobotModule> rest);

    @Override
    public String toString() {
        return "RobotModules{" +
                "type='" + type + '\'' +
                ", serial='" + serial + '\'' +
                ", ID=" + ID +
                '}';
    }

}
