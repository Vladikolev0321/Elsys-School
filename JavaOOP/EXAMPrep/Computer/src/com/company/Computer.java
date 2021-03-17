package com.company;

import java.util.ArrayList;
import java.util.List;

public class Computer {
    private List<IPart> components;

    public Computer(){
        components = new ArrayList<>();
    }
    public Computer(List<IPart> components) {
        this.components = components;
    }

    public PowerData getConsumption()throws Exception{

        double minPow = 0;
        double maxPow = 0;
        double typicalPow = 0;

        for(var part : components){
            minPow += part.getConsumption().getMinPower();
            maxPow += part.getConsumption().getMaxPower();
            typicalPow += part.getConsumption().getTypicalPower();
        }
        if(minPow <= 0 || maxPow <= 0 || typicalPow <= 0){
            throw new Exception("Power cannot should be positive");
        }

        int motherBoardCount = 0;
        for(var part : components){
            if(part instanceof MotherBoard){
                motherBoardCount++;
                if(motherBoardCount > 1){
                    throw new Exception("Can have only one motherboard");
                }
            }
        }

        int processorCount = 0;
        for(var part : components){
            if(part instanceof Processor){
                processorCount++;
                if(processorCount > 2){
                    throw new Exception("Can have only 2 processors");
                }
            }
        }

        return new PowerData(minPow, maxPow, typicalPow);
    }
}
