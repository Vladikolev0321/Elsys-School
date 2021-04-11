package com.company;

public class Sword extends Item implements Equippable, Usable{
    private int baseDamage;
    public Sword(String name, int baseDamage) {
        super(name);
        this.baseDamage = baseDamage;
    }

    @Override
    public void use(Character source, Character target) {
        if(source.getDextirity() > target.getDextirity())//increases damage of sword
        {
            target.setCurrentHealth(target.getCurrentHealth()-(baseDamage*2));
        }else{
            target.setCurrentHealth(target.getCurrentHealth()-(baseDamage));
        }
    }

}
