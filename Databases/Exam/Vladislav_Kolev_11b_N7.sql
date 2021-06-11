DROP DATABASE IF EXISTS Office;
CREATE DATABASE Office;
USE Office;


CREATE TABLE Office(
	id int not null auto_increment primary key,
	name varchar(100) unique not null 
);

CREATE TABLE Person(
	id int not null auto_increment primary key,
	name varchar(100) unique not null,
    age int not null,
    office_id int not null,
    FOREIGN KEY(office_id) REFERENCES Office(id),
    CHECK(age>0)
);
CREATE TABLE Entered(
	id int not null auto_increment primary key,
	date_of_entering datetime not null DEFAULT NOW(),
    person_id int not null,
    FOREIGN KEY(person_id) REFERENCES Person(id)
);

INSERT INTO Office(name) VALUES("Robopartans");
INSERT INTO Office(name) VALUES("Work and Share");
INSERT INTO Office(name) VALUES("Deliveroo");


INSERT INTO Person(name, age, office_id) VALUES("Misho", 25, 1);
INSERT INTO Person(name, age, office_id) VALUES("Ivan", 28, 1);
INSERT INTO Person(name, age, office_id) VALUES("Kiko", 35, 1);
INSERT INTO Person(name, age, office_id) VALUES("Georgi", 25, 2);
INSERT INTO Person(name, age, office_id) VALUES("Alex", 25, 2);


INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-02", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-03", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-04", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-01", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-03", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-04", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-30", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-05", 4);

# 1 -
SELECT Entered.date_of_entering, Office.name FROM Office
LEFT JOIN Person
ON Person.office_id = Office.id
RIGHT JOIN Entered
ON Entered.person_id = Person.id;

# 2 -
SELECT Count(Entered.id) FROM Entered
LEFT JOIN Person 
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Office.id = Person.office_id
WHERE Person.name = "Ivan";

# 3 -
SELECT Person.name, Count(Person.name) as "Count visits" FROM Entered
LEFT JOIN Person 
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Office.id = Person.office_id
WHERE month(Entered.date_of_entering) = 4 and year(Entered.date_of_entering) = 2020
GROUP BY Person.name
ORDER BY Count(Person.name)
LIMIT 1;

# 4 - 
SELECT Office.name, Count(Office.id) FROM Entered
LEFT JOIN Person 
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Office.id = Person.office_id
GROUP BY Office.name;

# 5 -
SELECT Office.name FROM Person
RIGHT JOIN Office
ON Office.id = Person.office_id
WHERE Person.office_id is null;


# 6 - 
SELECT Person.name FROM Entered
LEFT JOIN Person 
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Office.id = Person.office_id
GROUP BY Person.name;

