# Write your MySQL query statement below
SELECT e.name, b.bonus from Employee as e LEFT JOIN Bonus as b on e.empId  = b.empId  where b.bonus < 1000 or bonus is null;