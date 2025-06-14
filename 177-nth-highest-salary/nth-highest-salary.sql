CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offsetVal INT;
  SET offsetVal = N - 1;

  RETURN (
    SELECT salary
    FROM (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT offsetVal, 1
    ) AS temp
  );
END