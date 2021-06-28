package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Farmer {
    private String name;
    private List<String> instruments;
    private List<Posev> posevi;
    private List<Posev> deadPosevi;
    private List<Posev> obraniPosevi;

    public Farmer(String name, List<String> instruments) {
        this.name = name;
        this.instruments = instruments;
        posevi = new ArrayList<>();
        deadPosevi = new ArrayList<>();
        obraniPosevi = new ArrayList<>();
    }
    public Farmer(String name) {
        this.name = name;
        this.instruments = new ArrayList<>();
        posevi = new ArrayList<>();
//
        deadPosevi = new ArrayList<>();
        obraniPosevi = new ArrayList<>();
    }
    public void addPosev(Posev posev){
        posevi.add(posev);
    }
    public void addInstrument(String instr){
        instruments.add(instr);
    }
    public void minavanePrezPosevi(int countDays){
        for (int i = 0; i < countDays; i++){
            for (var p : posevi){
                //polivane
                if(((p instanceof Vegetable) || (p instanceof Fruit)) && instruments.contains("Leika")){
                    p.setPolqtoThisDay(true);
                }
                //brane
                if(p instanceof Vegetable && instruments.contains("Motika")){
                    if(p.getCurrentAge() == p.getNeededAge()){
                        p.obirane();
                        obraniPosevi.add(p);
                    }
                }else if(p instanceof Vegetable && instruments.contains("Stulba")){
                    if(p.getCurrentAge() == p.getNeededAge()){
                        p.obirane();

                        obraniPosevi.add(p);
                    }
                }else if(p instanceof Cactus && instruments.contains("Rukavici")){
                    if(p.getCurrentAge() == p.getNeededAge()){
                        p.obirane();

                        obraniPosevi.add(p);
                    }
                }
        }
            for (var posev : posevi){//
                if((!posev.isPolqtoThisDay) || posev.getCurrentAge() - 2 == posev.getNeededAge()){
                    posev.setDead(true);
                    deadPosevi.add(posev);
                }
            }
            // Age them
            posevi = posevi.stream().filter(po -> (po.isDead == false) && (po.isObran == false)).collect(Collectors.toList());
            for (var pos : posevi){
                pos.setCurrentAge(pos.getCurrentAge()+1);
            }
        }
    }

    public void getInfo(){
        System.out.println("Alive posevi");
        for (var pos : posevi){
            System.out.println(pos.getName());
        }
        System.out.println("Obrani posivi");
        for (var pos : obraniPosevi){
            System.out.println(pos.getName());
        }

        System.out.println("Dead posivi");
        for (var pos : deadPosevi){
            System.out.println(pos.getName());
        }
    }
}
