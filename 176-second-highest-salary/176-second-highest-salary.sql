SELECT max(Salary) as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)