DROP DATABASE IF EXISTS WEIGHT;
CREATE DATABASE WEIGHT;
USE WEIGHT;

Create Table Person(
    id int primary key not null auto_increment,
    name varchar(100) not null,
    age tinyint,
    height int,
    gender Enum("Male", "Female"),
    average_weight float,
    weight_in_count int default 0
);

Create Table Weight(
    id int primary key not null auto_increment,
    person_id int not null,
    foreign key (person_id) REFERENCES Person(id),
    value float not null,
    created_at timestamp default current_timestamp
);

Delimiter $$ 
Create Trigger Update_avg_weight
    Before Insert
    on Weight for each row
Begin
    Update Person
    Set average_weight = (
        Select AVG(value) from Weight
        Where person_id = NEW.person_id
    )
    WHERE Person.id = NEW.person_id;
End$$
Delimiter ;

Delimiter $$
Create Trigger Update_weight_times
    AFTER Insert      
    on Weight for each row
Begin
    Update Person
    Set weight_in_count = weight_in_count + 1
    WHERE Person.id = NEW.person_id;
End$$
Delimiter ;

Insert Into Person (name, age, height, gender) Values("Vladi", 17, 180 ,"Male");
Insert Into Person (name, age, height, gender) Values("Goshka", 23, 160 ,"Female");

Insert Into Weight(person_id, VALUE) Values(1, 70);
Insert Into Weight(person_id, VALUE) Values(1, 71);
Insert Into Weight(person_id, VALUE) Values(1, 72);
Insert Into Weight(person_id, VALUE) Values(1, 73);

Insert Into Weight(person_id, VALUE) Values(2, 50);
Insert Into Weight(person_id, VALUE) Values(2, 52);
Insert Into Weight(person_id, VALUE) Values(2, 54);

Select * from Person;

DROP DATABASE IF EXISTS WEIGHT;
