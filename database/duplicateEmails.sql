--
-- Sean
-- 2017-08-10
--
-- https://leetcode.com/problems/duplicate-emails/description/
--
-- Write a SQL query to find all duplicate emails in a table named Person.
--
-- +----+---------+
-- | Id | Email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- For example, your query should return the following for the above table:
--
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
-- Note: All emails are in lowercase.
--

-- Just to note that HAVING clause must come after GROUP BY
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(*) > 1;
