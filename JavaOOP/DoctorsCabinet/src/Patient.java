public class Patient {
    private String EGN;
    private String firstName;
    private String lastName;
    private Record record;

    public Patient(String EGN, String firstName, String lastName, Record record){
        this.EGN = EGN;
        this.firstName = firstName;
        this.lastName = lastName;
        this.record = record;
    }
    public Record getRecord()
    {
        return record;
    }


}
