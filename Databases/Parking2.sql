DROP DATABASE IF EXISTS PARKING;
CREATE DATABASE PARKING;
USE PARKING;

Create Table Person(
	id int not null primary key auto_increment,
	name varchar(100) unique not null,
    number_of_parked_cars int default 0
);
Create Table Car(
	id int not null primary key auto_increment,
    plate varchar(30) unique not null,
    person_id int not null,
    Foreign key(person_id) REFERENCES Person(id)
);
Create Table ParkingPlace(
	id int not null primary key auto_increment,
    car_id int unique not null,
    name varchar(50) unique not null,
    Foreign key(car_id) REFERENCES Car(id)
);

#Delimeter for increasing person parked count

Delimiter $$
Create Trigger Update_parked_count
    AFTER Insert      
    on ParkingPlace for each row
Begin
    Update Person
    Set number_of_parked_cars = number_of_parked_cars + 1
    WHERE Person.id IN (SELECT Car.person_id FROM Car WHERE Car.id = NEW.car_id) ;
End$$
Delimiter ;

Delimiter $$
Create Trigger Update_parked_count2
    AFTER Update      
    on ParkingPlace for each row
Begin
    Update Person
    Set number_of_parked_cars = number_of_parked_cars - 1
    WHERE Person.id IN (SELECT Car.person_id FROM Car WHERE Car.id = OLD.car_id) ;
    Update Person
    Set number_of_parked_cars = number_of_parked_cars + 1
    WHERE Person.id IN (SELECT Car.person_id FROM Car WHERE Car.id = NEW.car_id) ;
End$$
Delimiter ;

Delimiter $$
Create Trigger Update_parked_count3
    AFTER Delete      
    on ParkingPlace for each row
Begin
    Update Person
    Set number_of_parked_cars = number_of_parked_cars - 1
    WHERE Person.id IN (SELECT Car.person_id FROM Car WHERE Car.id = OLD.car_id) ;
End$$
Delimiter ;

#Insert in Person 
Insert Into Person (name) Values("Vladi");
Insert Into Person (name) Values("Koliq");
Insert Into Person (name) Values("Ivan");
Insert Into Person (name) Values("Gosho");
Insert Into Person (name) Values("Stamat");
Insert Into Person (name) Values("Gancho");
Insert Into Person (name) Values("Pesho");

#Insert in Car
Insert Into Car(plate, person_id) Values("CB666666",1);
Insert Into Car(plate, person_id) Values("CB943345",1);
Insert Into Car(plate, person_id) Values("CB945435",1);
Insert Into Car(plate, person_id) Values("C85S2334",1);
Insert Into Car(plate, person_id) Values("CB934957",2);
Insert Into Car(plate, person_id) Values("CB596486",2);
Insert Into Car(plate, person_id) Values("CB923234",2);
Insert Into Car(plate, person_id) Values("CB374848",3);
Insert Into Car(plate, person_id) Values("CB948888",3);
Insert Into Car(plate, person_id) Values("CB933333",4);

#Insert in ParkingPlace
Insert Into ParkingPlace(car_id, name) Values(1,"G21");
Insert Into ParkingPlace(car_id, name) Values(2,"G20");
Insert Into ParkingPlace(car_id, name) Values(3,"G50");
Insert Into ParkingPlace(car_id, name) Values(4,"A60");
Insert Into ParkingPlace(car_id, name) Values(5,"A70");
Insert Into ParkingPlace(car_id, name) Values(6,"A80");
Insert Into ParkingPlace(car_id, name) Values(7,"A12");
Insert Into ParkingPlace(car_id, name) Values(8,"A34");

#Select * From Person;
#Select * From Car;
#Select * From ParkingPlace;

UPDATE ParkingPlace
SET ParkingPlace.car_id = 10
WHERE ParkingPlace.id = 1;

DELETE FROM ParkingPlace WHERE name = "G21";


#All People with parked cars
Select Person.name from ParkingPlace
Left Join Car on Car.id = ParkingPlace.car_id
Left Join Person on Person.id = Car.person_id
GROUP BY Person.name
ORDER BY Person.name DESC;

#All car plates and name of parkingPlace on region G
SELECT Car.plate, ParkingPlace.name FROM ParkingPlace
LEFT JOIN Car ON Car.id = ParkingPlace.car_id
WHERE ParkingPlace.name LIKE "G%";


Select * from Person;
DROP DATABASE IF EXISTS PARKING;




