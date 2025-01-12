SELECT 
    S.user_id, 
    ROUND(
        IFNULL(
            (
                SUM(C.action = 'confirmed')
            ) / GREATEST(1, COUNT(C.user_id)),
            0
        ), 
        2
    ) AS confirmation_rate
FROM 
    Signups AS S
LEFT JOIN 
    Confirmations AS C
ON 
    S.user_id = C.user_id
GROUP BY 
    S.user_id;
