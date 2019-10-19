let greeting = (person: Person) => {
  switch (person.kind) {
    case SchoolPersonEnum.Teacher: 
      return "Hey Professor!"
    case SchoolPersonEnum.Director:
      return "Hello Director."
    case SchoolPersonEnum.Student:
      if(person.name === "Richard") return "Still here Ricky?"
      else return `Hey, ${person.name}.`
  }
}
