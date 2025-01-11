# Write your MySQL query statement below

SELECT E1.name
FROM Employee as E1 INNER JOIN Employee as E2
ON E1.id = E2.managerId
GROUP BY E1.id
HAVING COUNT(E2.managerId)>=5;