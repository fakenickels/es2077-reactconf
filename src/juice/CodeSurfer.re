type range = (int, int);

module Highlighter = {
  [@bs.module "./CodeSurferHighlighter"] [@react.component]
  external make:
    (
      ~code: string,
      ~language: string,
      ~noSurfing: bool,
      ~currentHighlights: option(range)
    ) =>
    React.element =
    "Highlighter";
};

[@react.component]
let make = (~code, ~language, ~highlights: array(range)) => {
  let length = Array.length(highlights) + 1;
  let currentStep = Hooks.useSteps(length);
  let noSurfing = currentStep == length || currentStep == 0;

  <div
    className=Css.(
      style([
        height(vh(100.)),
        width(vw(100.)),
        padding(px(30)),
        backgroundColor(hex("fbfbfb")),
        fontSize(px(30)),
        display(`flex),
        alignItems(center),
        justifyContent(center),
      ])
    )>
    <Highlighter
      noSurfing
      code
      language
      currentHighlights={highlights->Belt.Array.get(currentStep - 1)}
    />
  </div>;
};

let default = make;
