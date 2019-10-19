[@react.component]
let make = (~src) => {
  <img src className=Css.(style([ maxWidth(pct(100.)) ]))/>
}

let default = make
