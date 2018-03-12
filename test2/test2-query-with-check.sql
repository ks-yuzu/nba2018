-- another version
-- (check 'dept_id' found in 'employee' table using 'department' table)
WITH dept_emp AS (
  SELECT
    dept_id,
    COUNT(*) AS dept_emp_num,
    SUM(salary) AS dept_salary
  FROM employee GROUP BY dept_id
)

SELECT department.dept_id, dept_emp.dept_emp_num, dept_emp.dept_salary
  FROM department INNER JOIN dept_emp
  ON department.dept_id = dept_emp.dept_id;
