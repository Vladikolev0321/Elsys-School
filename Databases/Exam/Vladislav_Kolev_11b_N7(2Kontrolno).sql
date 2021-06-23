DROP DATABASE IF EXISTS Art;
CREATE DATABASE Art;
USE Art;


CREATE TABLE Person(
	id int not null auto_increment primary key,
	name varchar(100) unique not null,
    age int not null,
    CHECK(age>0)
);

CREATE TABLE Room(
	id int not null auto_increment primary key,
	name varchar(100) unique not null
);

CREATE TABLE Art(
	id int not null auto_increment primary key,
	name varchar(100) unique not null,
    price int not null,
    room_id int not null,
    FOREIGN KEY(room_id) REFERENCES Room(id),
    CHECK(price>0)
);

CREATE TABLE PersonRoom(
	id int not null auto_increment primary key,
    date_of_entering datetime not null,
    person_id int not null,
    FOREIGN KEY(person_id) REFERENCES Person(id),
    room_id int not null,
    FOREIGN KEY(room_id) REFERENCES Room(id)
);

INSERT INTO Person(name, age) VALUES("Misho", 20);
INSERT INTO Person(name, age) VALUES("Mimi", 21);
INSERT INTO Person(name, age) VALUES("Nasko", 24);

INSERT INTO Room(name) VALUES("205");
INSERT INTO Room(name) VALUES("200A");
INSERT INTO Room(name) VALUES("123");

INSERT INTO Art(name, price, room_id) VALUES("Beeple", 200, 3); 
INSERT INTO Art(name, price, room_id) VALUES("Vapsky", 20, 1); 
INSERT INTO Art(name, price, room_id) VALUES("Mona Lisa", 2, 2); 

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 1, 1);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 1, 1);

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-21", 1, 2);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-24", 1, 2);

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-25", 1, 3);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-31", 1, 3);

INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 3, 3);
INSERT INTO PersonRoom(date_of_entering, person_id, room_id) VALUES("2020-01-22", 3, 3);

# 1
SELECT Room.name FROM PersonRoom
LEFT JOIN Room
ON Room.id = PersonRoom.room_id
GROUP BY Room.name
ORDER BY COUNT(Room.id) DESC
LIMIT 1;

# 2
SELECT Person.name FROM PersonRoom
LEFT JOIN Room
ON Room.id = PersonRoom.room_id
Right JOIN Person
ON Person.id = PersonRoom.person_id
WHERE Room.name LIKE '2%'
GROUP BY Person.name;

# 3 

SELECT Person.name FROM PersonRoom
RIGHT JOIN Person
ON Person.id = PersonRoom.person_id
WHERE PersonRoom.person_id is null
GROUP BY Person.name;


# 4
SELECT Person.name, Count(PersonRoom.person_id) FROM PersonRoom
RIGHT JOIN Person
ON Person.id = PersonRoom.person_id
GROUP BY Person.name;

# 5
SELECT Person.name, Art.name FROM PersonRoom
LEFT JOIN Person
ON Person.id = PersonRoom.person_id
LEFT JOIN Room
ON Room.id = PersonRoom.room_id
LEFT JOIN Art
ON Art.room_id = Room.id
ORDER BY Art.price DESC;






