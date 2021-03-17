package com.company;

public class MotherBoard implements IPart{
    private String chipset;
    private int chipSetPower;

    public MotherBoard(String chipset) {
        this.chipset = chipset;
        if(chipset == "am1"){
            chipSetPower = 25;
        }
        else if(chipset == "am2"){
            chipSetPower = 35;
        }
        else if(chipset == "am3"){
            chipSetPower = 50;
        }
        else{
            chipSetPower = 30;
        }
    }

    @Override
    public PowerData getConsumption() {
        double typical = chipSetPower;
        double minPower = typical;
        double maxPower = typical;

        return new PowerData(minPower, maxPower, typical);
    }
}
