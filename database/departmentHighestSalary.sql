--
-- Sean
-- 2017-08-11
--
-- https://leetcode.com/problems/department-highest-salary/description/
--
-- The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.
--
-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Henry | 80000  | 2            |
-- | 3  | Sam   | 60000  | 2            |
-- | 4  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+
-- The Department table holds all departments of the company.
--
-- +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+
-- Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, Max has the highest salary in the IT department and Henry has the highest salary in the Sales department.
--
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | Sales      | Henry    | 80000  |
-- +------------+----------+--------+
--

-- first create a temporary table with highest salary and departmentId
-- then join them
SELECT
  D.Name AS Department,
  E.Name AS Employee,
  E.Salary AS Salary
FROM Employee E, Department D, (
  SELECT DepartmentId, MAX(Salary) AS HighestSalary
  FROM Employee
  GROUP BY DepartmentId
) tmp
WHERE
  E.DepartmentId = tmp.DepartmentId
  AND Salary = tmp.HighestSalary
  AND D.Id = E.DepartmentId;


-- a more explict JOIN version
SELECT
  D.Name AS Department,
  E.Name AS Employee,
  E.Salary AS Salary
FROM Employee E
JOIN Department D
    ON E.DepartmentId = D.Id
JOIN (
  SELECT DepartmentId, MAX(Salary) AS HighestSalary
  FROM Employee
  GROUP BY DepartmentId
) tmp
    ON E.DepartmentId = tmp.DepartmentId AND E.Salary = tmp.HighestSalary;
