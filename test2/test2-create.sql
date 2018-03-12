create table if not exists department(
  dept_id       integer     not null,
  dept_name     varchar(30) not null,
  dept_location varchar(30) not null,
  unique(dept_id)
);

create table if not exists employee(
  emp_id   integer     not null,
  emp_name varchar(50) not null,
  dept_id  integer     not null,
  salary   integer     not null,
  -- index dept_id,
  unique(emp_id)
);

insert or ignore into department (dept_id, dept_name, dept_location) values
  (10, 'Accounts',   'Delhi'    ),
  (20, 'Marketing',  'Delhi'    ),
  (30, 'IT',         'Warsaw'   ),
  (40, 'Production', 'Hyderabad'),
  (50, 'Sales',      'Bengaluru');

insert or ignore into employee (emp_id, emp_name, dept_id, salary) values
  ('1', 'Jojo',        20,  5000),
  ('2', 'Popat Lal',   30, 15000),
  ('3', 'Santa Singh', 40, 25000),
  ('4', 'Banta Singh', 20,  7500),
  ('5', 'Sohan Lal',   20, 15000),
  ('6', 'Kk',          10, 12000),
  ('7', 'Bob',         20, 35000),
  ('8', 'John',        30, 25000),
  ('9', 'Smith',       40,  5000);
