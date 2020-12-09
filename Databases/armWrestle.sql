DROP DATABASE IF EXISTS Canadska;
CREATE DATABASE Canadska;
Use Canadska;

Create Table Person(
    id int primary key auto_increment not null,
    name varchar(50) unique
);

Create Table Battle(
    id int primary key auto_increment not null,
    winner_id int not null,
    looser_id int not null,
    CHECK (winner_id != looser_id),
    FOREIGN KEY(winner_id) REFERENCES Person(id),
    FOREIGN KEY(looser_id) REFERENCES Person(id)
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

Select Count(winner_id) as count_wins FROM Battle
Left Join Person
ON Battle.winner_id = Person.id
WHERE Person.name = "Misho";


SELECT Person.name FROM Battle
LEFT JOIN Person
ON Battle.winner_id = Person.id
Where Battle.looser_id = 1
GROUP BY Person.name;

Select Battle.id, winner.name as winner, looser.name as looser FROM Battle
Left Join Person as winner
ON Battle.winner_id = winner.id
Left Join Person as looser
ON Battle.looser_id = looser.id;
