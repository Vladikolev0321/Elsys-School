package com.company;

public class Worker {
    protected String firstName;
    protected String lastName;
    protected int salary;

    public Worker(String firstName, String lastName, int salary) {
        if(salary <= 0)
        {
            throw new IllegalArgumentException("Salary must be positive");
        }

        this.firstName = firstName;
        this.lastName = lastName;
        this.salary = salary;
    }
}
