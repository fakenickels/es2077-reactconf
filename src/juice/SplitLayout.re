module Styles = {
  open Css;

  let wrapper = style([
    width(pct(100.)),
    height(pct(100.)),
    display(grid),
    gridTemplateColumns([fr(1.), fr(1.)]),
    gridColumnGap(px(15)),
    alignItems(center)
  ])
};


[@react.component]
let make = (~children) => {
  <div className=Styles.wrapper>
    children
  </div>
}

let default = make
