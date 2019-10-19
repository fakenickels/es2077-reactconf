enum SchoolPersonEnum {
  Teacher,
  Director,
  Student
}

interface Person {
  kind: SchoolPersonEnum
  name?: string;
}
