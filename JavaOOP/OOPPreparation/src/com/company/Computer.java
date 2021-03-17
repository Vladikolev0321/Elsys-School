package com.company;

import java.util.ArrayList;
import java.util.List;

public class Computer {

    private List<IPart> components = new ArrayList<>();

    public PowerData getConsumption() throws Exception{
        double sumTypical = 0;
        double sumMax = 0;
        double sumMin = 0;

        for (int i = 0; i < components.size(); i++){
            sumTypical += components.get(i).getConsumption().getTypicalPower();
            sumMax += components.get(i).getConsumption().getMaximalPower();
            sumMin += components.get(i).getConsumption().getMinimalPower();
        }
        if(sumTypical <= 0 || sumMax <= 0 || sumMin <= 0){
            throw new Exception("The power should be bigger than 0");
        }

        return new PowerData(sumMin, sumMax, sumTypical);
    }
}
