DROP DATABASE IF EXISTS School;
CREATE DATABASE School;
Use School;

CREATE TABLE Student
(	
	student_id int primary key auto_increment not null,
    name varchar(50) not null
);

CREATE TABLE StudentBook
(	
	id int primary key auto_increment not null,
    subject varchar(50) not null,
    publisher varchar(50) not null,
	student_id int,
    FOREIGN KEY(student_id) REFERENCES Student(student_id),
	UNIQUE KEY(subject, publisher) # makes the subject and publisher unique
);

CREATE TABLE Computer(
	id int primary key auto_increment not null,
    name varchar(50) not null 
);

CREATE TABLE Student_Computer(
	id int primary key auto_increment not null,
    student_id int,
    computer_id int,
    FOREIGN KEY (student_id) REFERENCES Student(student_id),
    FOREIGN KEY (computer_id) REFERENCES Computer(id)
);

INSERT INTO Student(name) VALUES("Misho");
INSERT INTO Student(name) VALUES("Mimi");

INSERT INTO StudentBook(subject, publisher, student_id) VALUES("Matematika", "Anubis", 1);
# Мими не може да има Математика на Анубис
INSERT INTO StudentBook(subject, publisher, student_id) VALUES("Matematika", "Anubis", 2);





