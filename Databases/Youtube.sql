DROP DATABASE IF EXISTS YouTube;
CREATE DATABASE YouTube;
USE YouTube;

CREATE TABLE Potrebitel(
	id int not null primary key auto_increment,
    name varchar(100) unique
);

CREATE TABLE Kanal(
	id int not null primary key auto_increment,
    name varchar(100) unique
);

CREATE TABLE PotrebitelKanal(
	id int not null primary key auto_increment,
    potrebitel_id int not null,
    FOREIGN KEY (potrebitel_id) REFERENCES Potrebitel(id),
    kanal_id int not null,
    FOREIGN KEY (kanal_id) REFERENCES Kanal(id),
    CONSTRAINT UniqueKanalPotrebitel Unique(kanal_id, potrebitel_id)
);

CREATE TABLE Video(
	id int not null primary key auto_increment,
    title varchar(100),
    kanal_id int not null,
    FOREIGN KEY (kanal_id) REFERENCES Kanal(id)
);
CREATE TABLE Komentar(
	id int not null primary key auto_increment,
    value varchar(500) not null,
    video_id int not null,
    FOREIGN KEY (video_id) REFERENCES Video(id),
    potrebitel_id int not null,
    FOREIGN KEY (potrebitel_id) REFERENCES Potrebitel(id)
);

INSERT INTO Potrebitel(name) VALUES("misho");
INSERT INTO Potrebitel(name) VALUES("mimi");
INSERT INTO Potrebitel(name) VALUES("nasko");


INSERT INTO Kanal(name) VALUES("MIsho & nasko");
INSERT INTO Kanal(name) VALUES("Make up");
INSERT INTO Kanal(name) VALUES("Vlog squad");


INSERT INTO Video(kanal_id, title) VALUES(1, "Kamchiq");
INSERT INTO Video(kanal_id, title) VALUES(1, "Thassos");
INSERT INTO Video(kanal_id, title) VALUES(2, "Fun du ten");
INSERT INTO Video(kanal_id, title) VALUES(2, "Nails");
INSERT INTO Video(kanal_id, title) VALUES(3, "We won a tesla");
INSERT INTO Video(kanal_id, title) VALUES(3, "Kamchiq");


INSERT INTO PotrebitelKanal(potrebitel_id, kanal_id) VALUES(1,3);
INSERT INTO PotrebitelKanal(potrebitel_id, kanal_id) VALUES(2,3);
INSERT INTO PotrebitelKanal(potrebitel_id, kanal_id) VALUES(3,3);

SELECT Potrebitel.name, Kanal.name FROM PotrebitelKanal
LEFT JOIN Potrebitel
ON PotrebitelKanal.potrebitel_id = Potrebitel.id
LEFT JOIN Kanal
ON PotrebitelKanal.kanal_id = Kanal.id;

SELECT Kanal.name, Video.title FROM Kanal
LEFT JOIN Video
ON Kanal.id = Video.kanal_id;

INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 1, 1);
INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 2, 1);
INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 3, 1);
INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 4, 1);

INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 5, 1);
INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("first", 6, 1);

INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("There is a giveaway", 3, 2);
INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("There is a giveaway", 4, 2);

#INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("I do not like myself", 5, 6);
#INSERT INTO Komentar(value, video_id, potrebitel_id) VALUES("I do not like myself", 6, 3);


SELECT Kanal.name, Video.title, Komentar.value, Potrebitel.name FROM Komentar
LEFT JOIN Video
ON Video.id = Komentar.video_id
LEFT JOIN Potrebitel
ON Komentar.potrebitel_id = Potrebitel.id
LEFT JOIN Kanal
ON Video.kanal_id = Kanal.id;


#Potrebitel.name, Komentar.value, K
SELECT komentirasht.name, Komentar.value, pritejavasht.name FROM Potrebitel as komentirasht
LEFT JOIN Komentar
ON Komentar.potrebitel_id = komentirasht.id
LEFT JOIN Video
ON Komentar.video_id = Video.id
LEFT JOIN Kanal
ON Video.kanal_id = Kanal.id
LEFT JOIN PotrebitelKanal
ON PotrebitelKanal.kanal_id = Kanal.id
LEFT JOIN Potrebitel as pritejavasht
ON PotrebitelKanal.potrebitel_id = pritejavasht.id;

SELECT Count(*) FROM Komentar
LEFT JOIN Potrebitel
ON Komentar.potrebitel_id = Potrebitel.id
WHERE Potrebitel.name LIKE "misho";