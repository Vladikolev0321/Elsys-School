package com.company;

import java.util.List;

public class Arm extends RobotModule{
    private int countJoints;
    private int maxKgLiftPower;
    private TypeArms typeArm;

    public Arm(String type, String serial, int ID, int countJoints, int maxKgLiftPower, TypeArms typeArm) {
        super(type, serial, ID);
        this.countJoints = countJoints;
        this.maxKgLiftPower = maxKgLiftPower;
        this.typeArm = typeArm;
    }

    @Override
    public void processCommand(String command) {
        var splitted = command.split(" ")
        if(splitted[1] == "rotate_left"){
            int angle = Integer.parseInt(splitted[2]);

        }
    }

    @Override
    public boolean isMinimumRequirementCovered(List<RobotModule> rest) {
        if(typeArm == TypeArms.withFingers){
            return rest.stream()
                    .filter(m -> m.getType() == "head")
                    .anyMatch((m) -> ((Head) m.isDoesHaveDeepVision()));
            int count = 0;
            for (var m : rest){
                if(m.getType() == "head"){
                    if((Head)m.isDoesHaveDeepVision()){
                        count++;
                    }
                }
            }
            if(count >= 1){
                return true;
            }else{
                return false;
            }
       }else{
            return true;
        }
    }
}
