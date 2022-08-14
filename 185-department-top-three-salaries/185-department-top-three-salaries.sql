SELECT Department,Employee,Salary
FROM
(SELECT
d.name AS Department,
e.name AS Employee,
e.Salary AS Salary,
dense_rank() over(PARTITION BY e.departmentId ORDER BY e.Salary DESC) AS rk
FROM Employee e
LEFT JOIN Department d ON e.departmentId = d.id) a
WHERE rk <= 3