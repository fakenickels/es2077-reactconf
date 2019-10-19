type result = | Loading | Error(string) | Data(array(string));
type status = | Enabled | Disabled;

[@react.component]
let make = (~result, ~status) => {
  /* You forgot to handle a possible case here, for example: (Enabled, Error _) */
  switch(status, result) {
    | (Enabled, Loading) => <p>{React.string("Loading...")}</p>
    | (Enabled, Data([||])) => <p>{React.string("List is empty!")}</p>
    | (Enabled, Data(list)) =>
      <ul>{list->Belt.Array.map(item => <li>{React.string(item)}</li>)->React.array}</ul>
    | (Disabled, _) => <p>{React.string("Unavailable.")}</p>
  } 
}
