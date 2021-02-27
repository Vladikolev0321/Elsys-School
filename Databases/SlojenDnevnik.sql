DROP DATABASE IF EXISTS SLOJEN_DNEVNIK;
CREATE DATABASE SLOJEN_DNEVNIK;
USE SLOJEN_DNEVNIK;


CREATE TABLE Student(
	student_id int primary key not null auto_increment,
    name varchar(50) not null,
    age int not null
);

CREATE TABLE Grades(
	grades_id int primary key not null auto_increment,
	student_id int not null,
    grade_name ENUM("BEL", "MATH", "SUBD") not null,
	grade int not null DEFAULT 2 CHECK(grade >= 2 AND grade <= 6),
	FOREIGN KEY(student_id) REFERENCES Student(student_id)
);


INSERT INTO Student(name, age) VALUES("Vladi", 17);
INSERT INTO Student(name, age) VALUES("Gosho", 17);


INSERT INTO Grades(student_id, grade_name, grade) VALUES(1, "BEL", 6);
INSERT INTO Grades(student_id, grade_name, grade) VALUES(1, "MATH", 6);
INSERT INTO Grades(student_id, grade_name, grade) VALUES(2, "BEL", 5);
INSERT INTO Grades(student_id, grade_name, grade) VALUES(2, "SUBD", 5);
INSERT INTO Grades(student_id, grade_name, grade) VALUES(2, "SUBD", 3);

INSERT INTO Grades(student_id, grade_name, grade) VALUES(1, "SUBD", 3);



SELECT * FROM Student;
SELECT * FROM Grades;

# AVG from all grades
SELECT AVG(g.grade) as Average FROM Grades as g;

SELECT AVG(g.grade) FROM Grades as g
WHERE g.student_id = 1;

SELECT s.name FROM Student as s
LEFT JOIN Grades as g
ON g.student_id = s.student_id
WHERE g.grade_name = "SUBD" AND g.grade BETWEEN 4 AND 6
GROUP BY s.name;

DROP DATABASE SLOJEN_DNEVNIK;