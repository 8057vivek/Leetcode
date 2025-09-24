CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      Select salary 
      from(
        select salary,
        dense_rank() over(order by salary desc) as rnum
        from Employee
      ) as ranked
      where rnum = N
      limit 1
  );
END