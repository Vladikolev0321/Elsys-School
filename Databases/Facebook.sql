DROP DATABASE IF EXISTS Facebook;
CREATE DATABASE Facebook;
Use Facebook;

CREATE TABLE GGroup(
	id int primary key auto_increment not null,
    name varchar(100) unique not null
);

CREATE TABLE User(
	id int primary key auto_increment not null,
    name varchar(50) unique not null
    # group_id int not null
);

CREATE TABLE Post(
	id int primary key auto_increment not null,
    name varchar(50) unique not null,
    content varchar(1000) not null,
	group_id int not null,
    FOREIGN KEY (group_id) REFERENCES GGroup(id)
);

CREATE TABLE CComment(
	id int primary key auto_increment not null,
    content varchar(1000) not null, 
    user_id int not null,
    post_id int not null,
    FOREIGN KEY (user_id) REFERENCES User(id),
    FOREIGN KEY (post_id) REFERENCES Post(id)
);

CREATE TABLE GROUPUSERS(
	id int primary key auto_increment not null,
    user_id int not null,
    group_id int not null,
    FOREIGN KEY (user_id) REFERENCES User(id),
    FOREIGN KEY (group_id) REFERENCES GGroup(id)
);

INSERT INTO GGroup(name) VALUES("Moqta Grupa");
INSERT INTO GGroup(name) VALUES("Vtora Grupa");


INSERT INTO User(name) VALUES("Vladi");
INSERT INTO User(name) VALUES("Gosho");
INSERT INTO User(name) VALUES("Sasho");

INSERT INTO Post(name, content, group_id) VALUES("Zdraveite1.1", "Tova e purvi post", 1);
INSERT INTO Post(name, content, group_id) VALUES("Zdraveite1.2", "Tova e vtori post", 1);
INSERT INTO Post(name, content, group_id) VALUES("Zdraveite2.1", "Tova e purvi post", 2);
INSERT INTO Post(name, content, group_id) VALUES("Zdraveite2.2", "Tova e vtori post", 2);

INSERT INTO CComment(content, user_id, post_id) VALUES("Comm1", 1, 2);
INSERT INTO CComment(content, user_id, post_id) VALUES("Comm2", 1, 2);
INSERT INTO CComment(content, user_id, post_id) VALUES("Comm3", 2, 2);

INSERT INTO GROUPUSERS(user_id, group_id) VALUES(1, 1);
INSERT INTO GROUPUSERS(user_id, group_id) VALUES(2, 1);

SELECT CComment.content as "Content", User.name as "Username", Post.name as "Post name", GGroup.name as "Group name"
FROM CComment
LEFT JOIN USER ON CComment.user_id = User.id
LEFT JOIN POST ON CComment.post_id = Post.id
LEFT JOIN GGroup ON Post.group_id = GGroup.id;

SELECT User.name as "User with no group" FROM User
LEFT JOIN CComment
ON CComment.user_id = User.id
WHERE CComment.user_id is null;

SELECT User.name as "In Group" FROM User
RIGHT JOIN GROUPUSERS ON User.id = GROUPUSERS.user_id
GROUP BY User.name;

SELECT GGroup.name as "Empty Groups" FROM GGroup
LEFT JOIN GROUPUSERS ON GGroup.id = GROUPUSERS.group_id
WHERE GROUPUSERS.group_id is null;

SELECT GGroup.name as "Group name", Post.name as "Post name", CComment.content as "Content" FROM GGroup 
LEFT JOIN Post ON GGroup.id = Post.group_id
LEFT JOIN CComment on Post.id = CComment.post_id
WHERE length(CComment.content) < 10;




 



