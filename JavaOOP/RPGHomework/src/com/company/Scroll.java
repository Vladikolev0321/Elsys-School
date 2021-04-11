package com.company;

public class Scroll extends Item implements Equippable, Usable{
    private int baseDamage;
    public Scroll(String name, int baseDamage) {
        super(name);
        this.baseDamage = baseDamage;
    }

    @Override
    public void use(Character source, Character target) {
        if(source.getIntelligence() - target.getIntelligence() < 0){//if intelligence is 0
            double diff = Math.abs(source.getIntelligence() - target.getIntelligence());
            diff *= 0.1;
            double currDamage = baseDamage - (double)baseDamage * diff;
            target.setCurrentHealth(target.getCurrentHealth()-(int)currDamage);
        }else if(source.getIntelligence() - target.getIntelligence() > 0){
            double diff = Math.abs(source.getIntelligence() - target.getIntelligence());
            diff *= 0.1;
            double currDamage = baseDamage + (double)baseDamage * diff;
            target.setCurrentHealth(target.getCurrentHealth()-(int)currDamage);
        }else{
            target.setCurrentHealth(target.getCurrentHealth()-baseDamage);
        }

    }
}
