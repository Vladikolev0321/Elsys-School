DROP DATABASE IF EXISTS Instagram;
CREATE DATABASE Instagram;
USE Instagram;

CREATE TABLE Profile(
	id int not null primary key auto_increment,
    username varchar(100) unique not null
);

CREATE TABLE Post(
	id int not null primary key auto_increment,
	description varchar(1000) not null,
    type ENUM('Video', 'Picture'),
    profile_id int not null REFERENCES Proflile(id)
);

CREATE TABLE Komentar(
	id int not null primary key auto_increment,
	value varchar(100) not null,
    profile_id int not null REFERENCES Proflile(id),
    post_id int not null REFERENCES Post(id)
);

CREATE TABLE LLike(
	id int not null primary key auto_increment,
    post_id int not null REFERENCES Post(id),
    profile_id int not null REFERENCES Profile(id),
    Constraint Uniqueness UNIQUE(post_id, profile_id)
);

CREATE TABLE Profile_LLike(
	id int not null primary key auto_increment,
	profile_id int not null REFERENCES Profile(id),
    like_id int not null REFERENCES LLike(id),
    Constraint Uniqueness Unique(profile_id, like_id)
);

INSERT INTO Profile(username) VALUES("hidr0frbg");
INSERT INTO Profile(username) VALUES("yourcasualnasko");
INSERT INTO Profile(username) VALUES("abigfan");


INSERT INTO Post(description, type, profile_id) VALUES("Parkour", "Video", 1);
INSERT INTO Post(description, type, profile_id) VALUES("Stunts", "Picture", 1);
INSERT INTO Post(description, type, profile_id) VALUES("BMW", "Video", 2);
INSERT INTO Post(description, type, profile_id) VALUES("Alfa", "Picture", 2);
INSERT INTO Post(description, type, profile_id) VALUES("My new car", "Picture", 2);

SELECT Profile.username, Post.description, Post.type FROM Profile
LEFT JOIN Post 
ON Post.profile_id = Profile.id
WHERE Post.description is not null;

SELECT Profile.username, Post.description, Post.type FROM Profile
RIGHT JOIN Post 
ON Post.profile_id = Profile.id;

INSERT INTO Komentar(value, post_id, profile_id) VALUES("Scary", 1, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Cool", 2, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Nice car", 3, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Ima li rujda", 4, 3);

SELECT  Komentiral.username as "Owner", Post.description, Komentar.value, Owner.username as "Komentiral" FROM Post
RIGHT JOIN Komentar
ON Komentar.post_id = Post.id
LEFT JOIN Profile as Komentiral
ON Komentiral.id = Komentar.profile_id
LEFT JOIN Profile as Owner
ON Owner.id = Post.profile_id;


INSERT INTO LLike(post_id, profile_id) VALUES(1, 1);
INSERT INTO LLike(post_id, profile_id) VALUES(1, 2);
INSERT INTO LLike(post_id, profile_id) VALUES(1, 3);
INSERT INTO LLike(post_id, profile_id) VALUES(2, 1);
INSERT INTO LLike(post_id, profile_id) VALUES(2, 2);

SELECT Post.description, Profile.username FROM Post
RIGHT JOIN LLike
ON LLike.post_id = Post.id
LEFT JOIN Profile
ON LLike.profile_id = Profile.id;


SELECT Owner.username as "Owner", Post.description, LLiker.username as "Liker", LLike.id FROM Post
LEFT JOIN Profile as Owner
ON Owner.id = Post.profile_id
RIGHT JOIN LLike as LLike
ON LLike.post_id = Post.id
LEFT JOIN Profile as LLiker
ON LLiker.id = LLike.profile_id; 



