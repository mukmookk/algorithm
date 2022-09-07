# Write your MySQL query statement below
# SELECT employee_id, IF (employee_id % 2 = 1 AND name NOT LIKE 'M%', salary, 0) as 'bonus'
# FROM Employees
# ORDER BY employee_id ASC;

SELECT employee_id, 
(CASE WHEN SUBSTRING(name, 1, 1) = 'M' or employee_id % 2 = 0 THEN 0
    ELSE salary
END) as bonus
FROM Employees
ORDER BY employee_id ASC;
# WHERE employee_Id % 2 <> 0 or SUBSTRING(name, 1, 1) <> 'M'

# SELECT employee_id,
# (CASE WHEN SUBSTRING(name, 1, 1) = 'M' or employee_id % 2 = 0 THEN 0 ELSE salary END) as bouns
# FROM Employees
