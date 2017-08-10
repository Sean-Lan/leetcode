-- Sean
-- 2017-08-10
--
-- https://leetcode.com/problems/nth-highest-salary/description/
--
-- Write a SQL query to get the nth highest salary from the Employee table.
--
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query should return null.
--
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
--

-- Similar to second highest salary problem, just to note that
-- only local variables are allowed in limit clause
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
          SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT 1 OFFSET M
      ) AS nthHighestSalary
  );
END
