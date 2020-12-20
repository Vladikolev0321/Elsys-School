DROP DATABASE IF EXISTS Dnevnik;
CREATE DATABASE Dnevnik;
Use Dnevnik;

CREATE TABLE Student(
	id int not null primary key auto_increment,
	name varchar(100) not null,
    age int not null
);

CREATE TABLE Grades(
	id int not null primary key auto_increment,
    grade_name Enum('Bel', 'Math', 'Subd'),
    grade int DEFAULT 2,
    student_id int,
    FOREIGN KEY(student_id) REFERENCES Student(id),
    Check(grade<=6 AND grade>=2)
);




