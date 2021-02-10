DROP DATABASE IF EXISTS Dnevnik;
CREATE DATABASE Dnevnik;
Use Dnevnik;


CREATE TABLE Grades(
	grades_id int primary key auto_increment not null,
    grade_bg int DEFAULT 2 CHECK(grade_bg >= 2 AND grade_bg <= 6) not null,
    grade_math int DEFAULT 2 CHECK(grade_math >= 2 AND grade_math <= 6) not null,
    grade_subd int DEFAULT 2 CHECK(grade_subd >= 2 AND grade_subd <= 6) not null
);
CREATE TABLE Student(
	id int primary key not null auto_increment,
    name varchar(40) not null,
    age int CHECK(age > 0) not null, 
    grades_id int unique,
	Foreign key(grades_id) REFERENCES Grades(grades_id) 
);

INSERT INTO Grades(grade_bg, grade_math, grade_subd) VALUES (6, 6, 6); 
INSERT INTO Grades(grade_bg, grade_math, grade_subd) VALUES (4, 5, 4); 
INSERT INTO Grades(grade_bg, grade_math, grade_subd) VALUES (5, 5, 5); 

INSERT INTO Student(name, age, grades_id) VALUES ("Vladi", 17, 1);
INSERT INTO Student(name, age, grades_id) VALUES ("Ivan", 17, 2);
INSERT INTO Student(name, age, grades_id) VALUES ("ALEX", 17, 3); 

Select * from Student;
Select * from Grades;

Select Student.id, Student.name, Student.age, grade_bg, grade_math, grade_subd
FROM Student
LEFT JOIN Grades
ON Student.grades_id = Grades.grades_id
WHERE Student.name = "ALEX";

Select Student.id, Student.name, Student.age, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student
LEFT JOIN Grades
ON Student.grades_id = Grades.grades_id
WHERE Student.name LIKE "%a%";

SELECT Student.id, Student.name, Student.age, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student 
LEFT JOIN Grades
ON Student.grades_id = Grades.grades_id
WHERE ((grade_bg + grade_math + grade_subd)/3) > 5;

SELECT Student.id, Student.name, Student.age, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student 
LEFT JOIN Grades
ON Student.grades_id = Grades.grades_id
WHERE ((grade_bg + grade_math)/2) > 5;







