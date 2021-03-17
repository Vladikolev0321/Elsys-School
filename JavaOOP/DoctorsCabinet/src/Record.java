public class Record {
    private String visitCard;
    private Symptoms symptoms;
    private String currDisese;

    public Record(String visitCard, Symptoms symptoms, String currDisese) {
        this.visitCard = visitCard;
        this.symptoms = symptoms;
        this.currDisese = currDisese;
    }

    public Symptoms getSymptoms() {
        return symptoms;
    }
}
