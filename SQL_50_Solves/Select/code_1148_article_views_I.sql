# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
From Views
Where author_id = viewer_id 
ORDER BY id;