package com.company;

import java.util.ArrayList;
import java.util.List;

public class Casino {
    private int countSlotMachines;
    private List<SlotMachine> slotMachines = new ArrayList<>();
    private List<Player> players = new ArrayList<>();

    public Casino(int countSlotMachines, List<SlotMachine> slotMachines, List<Player> players) {
        this.countSlotMachines = countSlotMachines;
        this.slotMachines = slotMachines;
        this.players = players;
    }
}
