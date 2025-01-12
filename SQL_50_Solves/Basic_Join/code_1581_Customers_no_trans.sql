# Write your MySQL query statement below

SELECT Visits.customer_id AS customer_id, COUNT(*) AS count_no_trans
FROM Visits LEFT JOIN Transactions 
ON Visits.visit_id = Transactions.visit_id
Where Transactions.transaction_id IS NULL
Group BY Visits.customer_id;
