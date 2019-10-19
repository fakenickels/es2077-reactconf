module Styles = {
  open Css;

  let wrapper = style([
    height(pct(100.)),
    width(pct(100.))
  ])
}

[@react.component]
let make = (~src) => {
  <video loop=true muted=true className=Styles.wrapper autoPlay=true>
    <source src={src} type_="video/mp4" />
  </video>
};

let default = make
