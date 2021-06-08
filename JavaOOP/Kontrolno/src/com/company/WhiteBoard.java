package com.company;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class WhiteBoard {
    private List<Task> exercises;

    public WhiteBoard(List<Task> exercises) {
        exercises = new ArrayList<>();
    }

    public Task getNextConsistentTask(int previousTaskNumber) throws NoMoreTaskException {
//        if(previousTaskNumber == 0){
//            return exercises.get(0);
//        }

        for (var task : exercises){
            if(task.getId() == previousTaskNumber+1){
                return task;
            }
        }
        throw new NoMoreTaskException();

    }

    public Task getNextSmartTask(int previousTaskNumber) throws NoMoreTaskException {
        exercises.sort(((o1, o2) -> o1.getPoints() - o2.getPoints()));


        for (int i = 0; i < exercises.size(); i++){
            if(exercises.get(i).getId() == previousTaskNumber){
                return exercises.get(i+1);
            }
        }
        throw new NoMoreTaskException();
    }


}
