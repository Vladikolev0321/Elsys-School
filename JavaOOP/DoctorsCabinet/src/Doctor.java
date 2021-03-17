import java.lang.reflect.Array;
import java.util.Dictionary;
import java.util.Hashtable;

public class Doctor {
    private String firstName;
    private String lastName;
    private Disease[] diseasesKnown;

    public Doctor(String firstName, String lastName, Disease[] diseasesKnown) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.diseasesKnown = diseasesKnown;
    }

    public Disease diagnose(Patient client, Symptoms[] symptoms){
        Hashtable<String, Integer> count = new Hashtable<>();
        for ()
        count.put("Cough", 0);
        count.put("HighTemperature", 0);
        count.put("ProblemsWithBreathing", 0);
        count.put("Vommiting", 0);
        count.put("Headache", 0);



        for(int i = 0; i < symptoms.length; i++){
            for(Symptoms currSymptom : Symptoms.values()){
                if(symptoms[i] == currSymptom){
                    count.put(symptoms[i], 0);
            }
            }
        }
    }
}
