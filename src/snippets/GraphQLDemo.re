module UserQuery = [%graphql {|
  query UserQuery {
    currentUser {
      name
      role
    }
  }
|}];

[@react.component]
let make = () => {
  let (result, _) = ReasonApolloHooks.useQuery(UserQuery.make());

  switch(result) {
    | Loading => <p>{React.string("Loading...")}</p>
    | Data(data) =>
      switch(data##currentUser) {
        | Some(user) => 
          switch(user##role) {
            | `ADMIN => <p>{React.string("Hello admin")}</p>
            | `OPERATOR => <p>{React.string("Hello operator")}</p>
          }
        | None => <p>{React.string("Not logged in")}</p>
      }
    | Error(_)
    | NoData(_) => <p>{React.string("Something went wrong")}</p>
  }
};
