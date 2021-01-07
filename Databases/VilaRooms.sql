DROP DATABASE IF EXISTS Vila;
CREATE DATABASE Vila;
Use Vila;

CREATE TABLE Room(
	id int primary key not null auto_increment,
    name varchar(3) unique,
    capacity int not null,
    price decimal(5,2) default 0
);
CREATE TABLE Person(
	id int primary key not null auto_increment,
    name varchar(30) unique,
    age int default 0 check(age > -1),
    room_id int,
    FOREIGN KEY (room_id) REFERENCES Room(id)
);
INSERT INTO Room(name,capacity, price) VALUES("A01", 2, 67.80);
INSERT INTO Room(name,capacity, price) VALUES("A02", 1, 42.80);
INSERT INTO Room(name,capacity, price) VALUES("A03", 1, 02.80);

INSERT INTO	Person(name, age, room_id) values("Misho", 23, 1);
INSERT INTO	Person(name, age, room_id) values("Ivan", 13, 1);
INSERT INTO	Person(name, age, room_id) values("Georgi", 15, 3);
INSERT INTO	Person(name, age) values("Marto", 26);
INSERT INTO	Person(name, age, room_id) values("Vladi", 18, 2);


SELECT * FROM Person
RIGHT JOIN Room
ON Person.room_id = Room.id;

SELECT * FROM Person
LEFT JOIN Room
ON Person.room_id = Room.id
Where Person.room_id is null;

SELECT Sum(price) From Person
RIGHT JOIN Room
On Person.room_id = Room.id;

ALTER TABLE Person Add type Enum("Mladej", "Vyzrasten");

UPDATE Person
SET type = "Mladej"
WHERE Person.age <= 18;

Update Person
SET type = "Vyzrasten"
WHERE Person.age > 18;
