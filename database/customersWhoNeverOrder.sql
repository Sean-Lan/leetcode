--
-- Sean
-- 2017-08-10
--
-- https://leetcode.com/problems/customers-who-never-order/description/
--
-- Suppose that a website contains two tables, the Customers table and the Orders table. Write a SQL query to find all customers who never order anything.
--
-- Table: Customers.
--
-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- Table: Orders.
--
-- +----+------------+
-- | Id | CustomerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+
-- Using the above tables as example, return the following:
--
-- +-----------+
-- | Customers |
-- +-----------+
-- | Henry     |
-- | Max       |
-- +-----------+
--

-- Left Excluding JOIN
SELECT Customers.Name AS Customers
FROM Customers LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;

-- NOT IN
SELECT C.Name AS Customers
FROM Customers C
WHERE C.Id NOT IN (
SELECT CustomerId FROM Orders
);
