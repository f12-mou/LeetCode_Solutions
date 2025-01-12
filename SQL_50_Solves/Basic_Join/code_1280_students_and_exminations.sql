# Write your MySQL query statement below

SELECT S1.student_id, S1.student_name, S2.subject_name, 
(
    SELECT COUNT(*) 
    FROM Examinations
    WHERE Examinations.student_id = S1.student_id 
    AND S2.subject_name = Examinations.subject_name

) AS attended_exams
FROM Students AS S1 
CROSS JOIN Subjects AS S2 
ORDER BY S1.student_id, S2.subject_name;
