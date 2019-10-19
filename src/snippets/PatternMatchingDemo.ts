import * as React from 'react'

interface Result {
  loading: boolean;
  error: string | null;
  data: string[] | null;
}

interface Props {
  result: Result;
  enabled: boolean;
}

export const List = ({ result, enabled }: Props) => {
  if(enabled) return <p>Unavailable</p>
  else {
    if(result.loading) return <p>Loading</p>
    if(result.data.length == []) return <p>List is empty!</p>
    if(result.data) return (
      <ul>{result.data.map(item => <li>{item}</li>)}</ul>
    )
  }
}
