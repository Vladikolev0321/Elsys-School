SELECT AVG(grade) AS AverageGrade FROM Grades;

SELECT AVG(grade) AS AverageGradeForStudentWithId1 FROM Grades
WHERE student_id = 1; 

SELECT grade_name AS "Subject", AVG(grade) AS "Average grade" FROM Grades
GROUP BY grade_name;

SELECT Student.name as "Student name",Grades.grade_name as "Grade name", Grades.grade as "Grade"
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
ORDER BY Student.name ASC;








