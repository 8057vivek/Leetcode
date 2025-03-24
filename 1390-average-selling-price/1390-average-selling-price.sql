WITH SalesWithPrice AS (
    SELECT 
        p.product_id, 
        COALESCE(SUM(p.price * u.units), 0) AS total_price,
        COALESCE(SUM(u.units), 0) AS total_units
    FROM Prices p
    LEFT JOIN UnitsSold u 
        ON p.product_id = u.product_id
        AND u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY p.product_id
)
SELECT 
    product_id, 
    CASE 
        WHEN total_units = 0 THEN 0
        ELSE ROUND(total_price / total_units, 2) 
    END AS average_price
FROM SalesWithPrice;
