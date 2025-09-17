# Write your MySQL query statement below
Select MAX(salary) as SecondHighestSalary FROM Employee where salary < 
    (Select MAX(salary) FROM Employee);