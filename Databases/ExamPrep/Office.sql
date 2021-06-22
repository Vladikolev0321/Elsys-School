DROP DATABASE IF EXISTS Office;
CREATE DATABASE Office;
USE Office;

CREATE TABLE Office(
	id int primary key auto_increment not null,
    name varchar(100) not null unique
);

CREATE TABLE Person(
	id int primary key auto_increment not null,
    name varchar(100) not null unique,
    age int not null,
    office_id int not null,
    FOREIGN KEY(office_id) REFERENCES Office(id),
    CHECK(age > 0)
);

CREATE TABLE Entered(
	id int primary key auto_increment not null,
    date_of_entering datetime not null DEFAULT now(),
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



-- [Датата на всяко влизане, Името на офис] => За всеки офис, който има влизания в него.
SELECT Entered.date_of_entering, Office.name FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Person.office_id = Office.id;





-- [Count] => Колко пъти Ivan е влизал в офиса
SELECT Count(Person.name) FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Person.office_id = Office.id
WHERE Person.name = 'Ivan';

-- [Името на човек, колко пъти е влизал в офиса] => За човек, който най-малко пъти е влизал в офиса си през месец Април 2020; Очакваме заявката да върне един човек, например [Pesho, 24]
SELECT Person.name, Count(Person.name) FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Person.office_id = Office.id
WHERE month(Entered.date_of_entering) = 4 and year(Entered.date_of_entering) = 2020
GROUP BY Person.name
ORDER BY Count(Person.name)
LIMIT 1;

-- [Името на офис, колко пъти е влизано в него] => За всеки офис.
SELECT Office.name, Count(Office.id) FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Person.office_id = Office.id
GROUP BY Office.name;



-- [Името на офис] => За всеки офис, който няма хора в него;
SELECT Office.name FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
RIGHT JOIN Office
ON Person.office_id = Office.id
WHERE Person.id is null;


SELECT Office.name FROM Person
RIGHT JOIN Office
ON Office.id = Person.office_id
WHERE Person.office_id is null;


-- [Името на чокве] => За всеки човек, който е влизал в офиса си поне един път. Очакваме да изпишем името на човек само единт път.
SELECT Person.name FROM Entered
LEFT JOIN Person
ON Person.id = Entered.person_id
LEFT JOIN Office
ON Person.office_id = Office.id
GROUP BY Person.name;


