# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
Where CHAR_LENGTH(content)>15;