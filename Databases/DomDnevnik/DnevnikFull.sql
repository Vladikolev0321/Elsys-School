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

INSERT INTO Student(name, age) VALUES("Vladi", 17);
INSERT INTO Student(name, age) VALUES("Stamat", 21);

INSERT INTO Grades(grade_name, grade, student_id) VALUES("Bel", 3, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Bel", 3, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Bel", 4, 2);
INSERT INTO Grades(grade_name, student_id) VALUES("Bel", 2);

INSERT INTO Grades(grade_name, grade, student_id) VALUES("Math", 2, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Math", 4, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Math", 6, 2);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Math", 3, 2);

INSERT INTO Grades(grade_name, grade, student_id) VALUES("Subd", 4, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Subd", 3, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Subd", 6, 2);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("Subd", 5, 2);

SELECT AVG(grade) AS AverageGrade FROM Grades;

SELECT AVG(grade) AS AverageGradeForStudentWithId1 FROM Grades
WHERE student_id = 1; 

SELECT grade_name AS "Subject", AVG(grade) AS "Average grade" FROM Grades
GROUP BY grade_name;

SELECT Student.name as "Student name",Grades.grade_name as "Grade name", Grades.grade as "Grade"
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
ORDER BY Student.name ASC;

DROP TABLE IF EXISTS Grades;
DROP TABLE IF EXISTS Student;
DROP DATABASE IF EXISTS Dnevnik;