DROP DATABASE IF EXISTS Fight;
CREATE DATABASE Fight;
USE Fight;

CREATE TABLE Club(
	id int not null primary key auto_increment,
    name varchar(100) unique not null
);

CREATE TABLE Person(
	id int not null primary key auto_increment,
    name varchar(100) unique not null,
    age int not null,
    club_id int not null REFERENCES Club(id),
	CHECK(age>0)
);

CREATE TABLE Fight(
	id int not null primary key auto_increment,
    fight_date datetime not null DEFAULT now(),
    winner_id int not null REFERENCES Person(id),
    looser_id int not null REFERENCES Person(id),
    CHECK(winner_id != looser_id)
);


INSERT INTO Club(name) VALUES("Club 1");
INSERT INTO Club(name) VALUES("Club 2");
INSERT INTO Club(name) VALUES("Club 3");

INSERT INTO Person(name, club_id, age) VALUES("Misho", 1, 20);
INSERT INTO Person(name, club_id, age) VALUES("Nasko", 1, 20);
INSERT INTO Person(name, club_id, age) VALUES("Mitko", 1, 20);
INSERT INTO Person(name, club_id, age) VALUES("Georgi", 2, 20);
INSERT INTO Person(name, club_id, age) VALUES("Mimi", 2, 21);

INSERT INTO Fight(winner_id, looser_id) VALUES(1,2);
INSERT INTO Fight(winner_id, looser_id) VALUES(2,3);
INSERT INTO Fight(winner_id, looser_id) VALUES(3,4);
INSERT INTO Fight(winner_id, looser_id) VALUES(4,2);
INSERT INTO Fight(winner_id, looser_id) VALUES(1,2);

# equal to second
SELECT Person.name, Fight.fight_date FROM Person
RIGHT JOIN Fight
ON Fight.winner_id = Person.id;

# equal to first query
SELECT Person.name, Fight.fight_date FROM Fight
LEFT JOIN Person
ON Person.id = Fight.winner_id;

SELECT Person.name, Fight.fight_date FROM Fight
LEFT JOIN Person
ON Person.id = Fight.looser_id;

SELECT Winner.name, Loser.name FROM Fight
LEFT JOIN Person as Winner
ON Winner.id = Fight.winner_id
LEFT JOIN Person as Loser
ON Loser.id = Fight.looser_id;

SELECT Winner_club.name, Loser_club.name FROM Fight
LEFT JOIN Person as Winner
ON Winner.id = Fight.winner_id
LEFT JOIN Person as Loser
ON Loser.id = Fight.looser_id
LEFT JOIN Club as Winner_club
ON Winner_club.id = Winner.club_id
LEFT JOIN Club as Loser_club
ON Loser_club.id = Loser.club_id;

SELECT * FROM Person
LEFT JOIN Fight as winners
ON winners.winner_id = Person.id
WHERE winners.winner_id is null;

SELECT * FROM Person
LEFT JOIN Fight as loosers
ON loosers.looser_id = Person.id
WHERE loosers.looser_id is null;

SELECT * FROM Person
LEFT JOIN Fight as loosers
ON loosers.looser_id = Person.id
LEFT JOIN Fight as winners
ON winners.winner_id = Person.id
WHERE loosers.looser_id is null and winners.winner_id is null;




