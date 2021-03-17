DROP DATABASE IF EXISTS School;
CREATE DATABASE School; 
USE School;

CREATE TABLE SchoolGroup(
	id int primary key not null auto_increment,
    name varchar(40) not null,
    first_meeting timestamp default Current_Timestamp
);

CREATE TABLE Member(
	id int primary key not null auto_increment,
    name varchar(40) not null,
    group_id int not null,
    type ENUM("student", "teacher"),
    FOREIGN KEY(group_id) REFERENCES SchoolGroup(id)
);

INSERT INTO SchoolGroup(name, first_meeting) VALUES("First Group", "2010-10-10 0:0:1");# 00:00:02 10.10.2010
INSERT INTO SchoolGroup(name, first_meeting) VALUES("Second Group", "2020-01-02 10:10:10");# 00:00:00 10.10.2010
INSERT INTO SchoolGroup(name) VALUES("Third Group");


INSERT INTO Member(name, group_id, type) VALUES("Vladi", 1, "student");
INSERT INTO Member(name, group_id, type) VALUES("Pesho", 1, "student");
INSERT INTO Member(name, group_id, type) VALUES("Teacher1", 1, "teacher");
INSERT INTO Member(name, group_id, type) VALUES("Teacher2", 2, "teacher");
# INSERT INTO Member(name, group_id, type) VALUES("Vladi", 1, "student");

SELECT * FROM SchoolGroup;

# 2
SELECT g.name, m.name, m.type FROM SchoolGroup as g
LEFT JOIN Member as m
ON m.group_id = g.id;

# 3
SELECT g.name, count(m.name) FROM SchoolGroup as g
LEFT JOIN Member as m
ON m.group_id = g.id
GROUP BY g.name;

# 4

SELECT g.name, count(m.name) FROM SchoolGroup as g
LEFT JOIN Member as m
ON m.group_id = g.id
WHERE m.type = "student"
GROUP BY g.name;

# 5 

SELECT g.name, count(m.name) FROM SchoolGroup as g
LEFT JOIN Member as m
ON m.group_id = g.id
WHERE m.type = "teacher"
GROUP BY g.name;

# 6

SELECT * FROM SchoolGroup as g
WHERE g.first_meeting > "2010-10-10 00:00:00" AND  g.first_meeting < "2011-11-11 23:59:59";

DROP DATABASE School;