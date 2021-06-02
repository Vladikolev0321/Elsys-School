DROP DATABASE IF EXISTS Fight;
CREATE DATABASE Fight;
USE Fight;

CREATE TABLE Club(
	id int not null primary key auto_increment,
    name varchar(200) unique not null
);
CREATE TABLE Person(
	id int primary key not null auto_increment,
    name varchar(200) unique not null,
    age int not null,
    club_id int not null,
    FOREIGN KEY(club_id) REFERENCES Club(id),
    CHECK(age>0)
);
CREATE TABLE Fight(
	id int primary key not null auto_increment,
	fight_data datetime not null DEFAULT NOW(),
    winner_id int not null,
    FOREIGN KEY(winner_id) REFERENCES Person(id),
    looser_id int not null,
    FOREIGN KEY(looser_id) REFERENCES Person(id),
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
# INSERT INTO Fight(winner_id, looser_id) VALUES(1,1);

SELECT Person.name, Fight.fight_data FROM Fight
LEFT JOIN Person
ON Person.id = Fight.winner_id;

SELECT Person.name, Fight.fight_data FROM Fight
LEFT JOIN Person
ON Person.id = Fight.looser_id;

SELECT winner.name, looser.name FROM Fight
LEFT JOIN Person as winner
ON winner.id = Fight.winner_id
LEFT JOIN Person as looser
ON looser.id = Fight.looser_id;


SELECT winner.name, looser.name FROM Fight
LEFT JOIN Person as winner
ON winner.id = Fight.winner_id
LEFT JOIN Person as looser
ON looser.id = Fight.looser_id;

SELECT Club_winner.name, Club_looser.name FROM Fight
LEFT JOIN Person as winner
ON winner.id = Fight.winner_id
LEFT JOIN Person as looser
ON looser.id = Fight.looser_id
LEFT JOIN  Club as Club_winner
ON Club_winner.id = winner.club_id
LEFT JOIN  Club as Club_looser
ON Club_looser.id = looser.club_id;


SELECT * FROM Person
LEFT JOIN Fight as winner
ON winner.winner_id = Person.id
WHERE winner_id is null;

SELECT * FROM Person
LEFT JOIN Fight
ON Fight.looser_id = Person.id
WHERE looser_id is null;


SELECT * FROM Person
LEFT JOIN Fight as winner
ON winner.winner_id = Person.id
LEFT JOIN Fight as looser
ON looser.looser_id = Person.id
WHERE winner.id is null and looser.id is null;







