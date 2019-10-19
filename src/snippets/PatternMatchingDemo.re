type result = | Loading | Error(string) | Data(array(string));
type status = | Enabled | Disabled;

[@react.component]
let make = (~result, ~status) => {
  switch(status, result) {
    | (Enabled, Loading) => <p>{React.string("Loading...")}</p>
    | (Enabled, Error(error)) => <p>{React.string("Something went wrong: " ++ error)}</p>
    | (Enabled, Data([||])) => <p>{React.string("List is empty!")}</p>
    | (Enabled, Data(list)) =>
      <ul>{list->Belt.Array.map(item => <li>{React.string(item)}</li>)->React.array}</ul>
    | (Disabled, _) => <p>{React.string("Unavailable.")}</p>
  } 
}
