--
-- Sean
-- 2017-08-10
--
-- https://leetcode.com/problems/employees-earning-more-than-their-managers/description/
--
-- The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.
--
-- +----+-------+--------+-----------+
-- | Id | Name  | Salary | ManagerId |
-- +----+-------+--------+-----------+
-- | 1  | Joe   | 70000  | 3         |
-- | 2  | Henry | 80000  | 4         |
-- | 3  | Sam   | 60000  | NULL      |
-- | 4  | Max   | 90000  | NULL      |
-- +----+-------+--------+-----------+
-- Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.
--
-- +----------+
-- | Employee |
-- +----------+
-- | Joe      |
-- +----------+
--

-- Join the Employee table by itself
SELECT E.Name AS Employee
FROM Employee E, Employee M
WHERE E.ManagerId = M.Id AND E.Salary > M.Salary;

-- More explictly with JOIN
SELECT E.Name AS Employee FROM
Employee E JOIN Employee M
ON E.ManagerId = M.Id
WHERE E.Salary > M.Salary;
