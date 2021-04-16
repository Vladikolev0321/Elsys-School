DROP DATABASE IF EXISTS School;
CREATE DATABASE School;
Use School;

CREATE TABLE Student
(	
	student_id int primary key auto_increment not null,
    name varchar(50) not null
);

CREATE TABLE Computer(
	id int primary key auto_increment not null,
    model varchar(50) not null 
);

CREATE TABLE Student_Computer(
	id int primary key auto_increment not null,
    student_id int,
    computer_id int,
    FOREIGN KEY (student_id) REFERENCES Student(student_id),
    FOREIGN KEY (computer_id) REFERENCES Computer(id),
	UNIQUE KEY(student_id, computer_id)  # makes the student_id and computer_id unique
);

INSERT INTO Student(name) VALUES("Misho");
INSERT INTO Student(name) VALUES("Mimi");

INSERT INTO Computer(model) VALUES("MishosComputer");
INSERT INTO Computer(model) VALUES("MimisComputer");

INSERT INTO Student_Computer(student_id, computer_id) VALUES(1, 1);
INSERT INTO Student_Computer(student_id, computer_id) VALUES(1, 2);
INSERT INTO Student_Computer(student_id, computer_id) VALUES(2, 1);
INSERT INTO Student_Computer(student_id, computer_id) VALUES(2, 2);
#  не може да посети един и същи компютър повече от един път
# ще хвърли error
INSERT INTO Student_Computer(student_id, computer_id) VALUES(1, 1);


