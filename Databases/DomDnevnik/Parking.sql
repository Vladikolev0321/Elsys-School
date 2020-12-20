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
/*Create Table ParkingPlace(
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
    WHERE Car.id = NEW.id;
End$$
Delimiter ;
*/

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
Insert Into Car(plate, person_id) Values("CB948888",4);
Insert Into Car(plate, person_id) Values("CB933333",2);

#Insert in ParkingPlace
Insert Into ParkingPlace(car_id, name) Values(1,"A21");
Insert Into ParkingPlace(car_id, name) Values(2,"A20");
Insert Into ParkingPlace(car_id, name) Values(3,"A50");
Insert Into ParkingPlace(car_id, name) Values(4,"A60");
Insert Into ParkingPlace(car_id, name) Values(5,"A70");
Insert Into ParkingPlace(car_id, name) Values(6,"A80");
Insert Into ParkingPlace(car_id, name) Values(7,"A12");
Insert Into ParkingPlace(car_id, name) Values(8,"A34");
Insert Into ParkingPlace(car_id, name) Values(9,"A64");

Select * From Person;
#Select * From Car;
#Select * From ParkingPlace;

Select Person.name from ParkingPlace
Left Join Car on Car.id = ParkingPlace.car_id
Left Join Person on Person.id = Car.person_id;

DROP DATABASE IF EXISTS PARKING;




