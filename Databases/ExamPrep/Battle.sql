DROP DATABASE IF EXISTS Battle;
CREATE DATABASE Battle;
USE Battle;

CREATE TABLE Person(
	id int not null auto_increment primary key,
    name varchar(100) unique not null
);
CREATE TABLE Battle(
	id int not null auto_increment primary key, 
    winner_id int not null REFERENCES Person(id),
    looser_id int not null REFERENCES Person(id),
    CHECK(winner_id != looser_id)
);

INSERT INTO Person(name) VALUES("Misho");
INSERT INTO Person(name) VALUES("Gosho");
INSERT INTO Person(name) VALUES("Ivan");
INSERT INTO Person(name) VALUES("Pesho");
INSERT INTO Person(name) VALUES("Mitio");

INSERT INTO Battle(winner_id, looser_id) VALUES(1,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,2);

SELECT Count(*) FROM Person
LEFT JOIN Battle
ON Battle.winner_id = Person.id
WHERE Person.name = "Misho";

SELECT winners.name FROM Battle
LEFT JOIN Person as loosers
ON loosers.id = Battle.looser_id
LEFT JOIN Person as winners
ON winners.id = Battle.winner_id
WHERE loosers.name = "Misho"
GROUP BY winners.name;


-- SELECT * FROM Battle
-- LEFT JOIN Person as loosers
-- ON loosers.id = Battle.looser_id
-- LEFT JOIN Person as winners
-- ON winners.id = Battle.winner_id
-- WHERE loosers.name = "Misho";

SELECT Battle.id, winners.name, looser.name FROM Battle
LEFT JOIN Person as winners
ON winners.id = Battle.winner_id
LEFT JOIN Person as looser
on looser.id = Battle.looser_id;

