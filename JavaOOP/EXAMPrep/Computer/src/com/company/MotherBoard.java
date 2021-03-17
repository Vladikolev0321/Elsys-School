package com.company;

public class MotherBoard implements IPart{
    private String chipSetName;

    public MotherBoard(String chipSetName) {
        this.chipSetName = chipSetName;
    }

    @Override
    public PowerData getConsumption() {
        double typicalPow;
        if(chipSetName == "am1"){
            typicalPow = 25;
        }else if(chipSetName == "am2"){
            typicalPow = 35;
        }else if(chipSetName == "am3"){
            typicalPow = 50;
        }else{
            typicalPow = 30;
        }

        double minPow = typicalPow;
        double maxPow = typicalPow;

        return new PowerData(minPow, maxPow, typicalPow);
    }
}
