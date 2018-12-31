CREATE TABLE faculty (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  Name TEXT  NOT NULL    ,
PRIMARY KEY(ID))
;

CREATE TABLE discipline (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  Name TEXT  NOT NULL    ,
PRIMARY KEY(ID))
;

CREATE TABLE specialty (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  faculty_ID INTEGER  NOT NULL  ,
  Code TEXT  NOT NULL    ,
PRIMARY KEY(ID)  ,
INDEX Specialty_FKIndex1(faculty_ID),
  FOREIGN KEY(faculty_ID)
    REFERENCES faculty(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION)
;

CREATE TABLE professor (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  faculty_ID INTEGER  NOT NULL  ,
  discipline_ID INTEGER  NOT NULL  ,
  Name TEXT  NOT NULL  ,
  Surname TEXT  NOT NULL    ,
PRIMARY KEY(ID)  ,
INDEX Professor_FKIndex1(faculty_ID)  ,
INDEX Professor_FKIndex2(discipline_ID),
  FOREIGN KEY(faculty_ID)
    REFERENCES faculty(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION,
  FOREIGN KEY(discipline_ID)
    REFERENCES discipline(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION)
;

CREATE TABLE squad (
  ID INTEGER  NOT NULL  AUTO_INCREMENT,
  specialty_ID INTEGER  NOT NULL   ,
  Name TEXT  NOT NULL    ,
PRIMARY KEY(ID)  ,
INDEX Groups_FKIndex1(specialty_ID),
  FOREIGN KEY(specialty_ID)
    REFERENCES specialty(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION)
;

CREATE TABLE student (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  squad_ID INTEGER  NOT NULL  ,
  Name TEXT  NOT NULL  ,
  Surname TEXT  NOT NULL    ,
PRIMARY KEY(ID)  ,
INDEX Student_FKIndex1(squad_ID),
  FOREIGN KEY(squad_ID)
    REFERENCES squad(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION)
;

CREATE TABLE coursework (
  ID INTEGER  NOT NULL   AUTO_INCREMENT,
  student_ID INTEGER  NOT NULL  ,
  professor_ID INTEGER  NOT NULL  ,
  discipline_ID INTEGER  NOT NULL  ,
  Title TEXT  NOT NULL  ,
  Mark INTEGER  NOT NULL    ,
PRIMARY KEY(ID)  ,
INDEX CourseWork_FKIndex1(student_ID)  ,
INDEX CourseWork_FKIndex2(professor_ID)  ,
INDEX CourseWork_FKIndex3(discipline_ID),
  FOREIGN KEY(student_ID)
    REFERENCES student(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION,
  FOREIGN KEY(professor_ID)
    REFERENCES professor(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION,
  FOREIGN KEY(discipline_ID)
    REFERENCES discipline(ID)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION)
;
CREATE INDEX Mark ON work(Mark);