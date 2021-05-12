DROP DATABASE IF EXISTS Instagram;
CREATE DATABASE Instagram;
USE Instagram;

CREATE TABLE Profile(
	id int not null auto_increment primary key,
    username varchar(100) unique not null
);

CREATE TABLE Post(
	id int not null auto_increment primary key,
    description varchar(100) not null,
    type enum('Video', 'Picture'),
    profile_id int REFERENCES Profile(id)
);

CREATE TABLE Komentar (
	id int not null auto_increment primary key,
	value varchar(200) not null,
    post_id int not null REFERENCES Post(id),
	profile_id int not null REFERENCES Profile(id)
);

CREATE TABLE LLike (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    post_id int not null REFERENCES Post(id),
    profile_id INT REFERENCES Profile(id),
    Constraint Uniqueness UNIQUE(post_id, profile_id)
);

CREATE TABLE Profile_LLike(
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    profile_id INT REFERENCES Profile(id),
    like_id INT REFERENCES LLike(id),
    Constraint Uniqueness UNIQUE(profile_id, like_id)
);

INSERT INTO Profile(username) VALUES("vladi");
INSERT INTO Profile(username) VALUES("tedo");
INSERT INTO Profile(username) VALUES("fan");

INSERT INTO Post(description, type, profile_id) VALUES("Parkour", "Video", 1);
INSERT INTO Post(description, type, profile_id) VALUES("Stunts", "Picture", 2);
INSERT INTO Post(description, type, profile_id) VALUES("BMW", "Video", 2);
INSERT INTO Post(description, type, profile_id) VALUES("Alpha", "Picture", 2);
INSERT INTO Post(description, type, profile_id) VALUES("My new car", "Picture", 3);

SELECT Profile.username, Post.description, Post.type FROM Profile
LEFT JOIN Post ON Profile.id = Post.profile_id
WHERE Post.description is not null;

SELECT Profile.username, Post.description, Post.type FROM Profile
RIGHT JOIN Post ON Profile.id = Post.profile_id;

INSERT INTO Komentar(value, post_id, profile_id) VALUES("Scary", 1, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Cool", 2, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Nice car", 3, 3);
INSERT INTO Komentar(value, post_id, profile_id) VALUES("Ima li rujda", 4, 3);

SELECT Komentiral.username as "Owner", Post.description, Komentar.value, Owner.username as "Komentiral"
FROM Post
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
ON Profile.id = LLike.profile_id;

SELECT Owner.username as "Owner", Post.description, LLiker.username as "Liker", LLike.id
FROM Post
LEFT JOIN Profile as Owner
ON Owner.id = Post.profile_id
RIGHT JOIN LLike
ON LLike.post_id = Post.id
LEFT JOIN Profile as LLiker
ON LLiker.id = LLike.profile_id;





