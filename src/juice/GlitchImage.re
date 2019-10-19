/* Reference https://tympanus.net/Tutorials/CSSGlitchEffect/index.html */

module Styles = {
  open Css;

  let wrapper = (~src) => style([
    width(pct(100.)),
    height(pct(100.)),
    backgroundImage(`url(src)),
    backgroundRepeat(noRepeat),
    backgroundSize(cover),
    overflow(hidden),
    position(relative),
  ]);

  let glitchAnimation1Horizontal = keyframes([
    (0, [
     unsafe("clip-path", "polygon(0 2%, 100% 2%, 100% 5%, 0 5%)"),
    ]),
    (5, [
     unsafe("clip-path", "polygon(0 15%, 100% 15%, 100% 15%, 0 15%)"),
    ]),
    (10, [
     unsafe("clip-path", "polygon(0 10%, 100% 10%, 100% 20%, 0 20%)"),
    ]),
    (15, [
     unsafe("clip-path", "polygon(0 1%, 100% 1%, 100% 2%, 0 2%)"),
    ]),
    (20, [
     unsafe("clip-path", "polygon(0 33%, 100% 33%, 100% 33%, 0 33%)"),
    ]),
    (25, [
     unsafe("clip-path", "polygon(0 44%, 100% 44%, 100% 44%, 0 44%)"),
    ]),
    (30, [
     unsafe("clip-path", "polygon(0 50%, 100% 50%, 100% 20%, 0 20%)"),
    ]),
    (35, [
     unsafe("clip-path", "polygon(0 70%, 100% 70%, 100% 70%, 0 70%)"),
    ]),
    (40, [
     unsafe("clip-path", "polygon(0 80%, 100% 80%, 100% 80%, 0 80%)"),
    ]),
    (45, [
     unsafe("clip-path", "polygon(0 50%, 100% 50%, 100% 55%, 0 55%)"),
    ]),
    (50, [
     unsafe("clip-path", "polygon(0 70%, 100% 70%, 100% 80%, 0 80%)"),
    ]),
    (51, [
     unsafe("clip-path", "polygon(0 0, 0 0)"),
    ]),
    (100, [
     unsafe("clip-path", "polygon(0 0, 0 0)"),
    ]),
  ])

  let glitch  = (~src, ~animDuration=600, ~bgColor, ~blendMode, ~animationName=glitchAnimation1Horizontal, ()) => style([
    position(absolute),
    top(zero),
    left(zero),
    width(pct(110.)),
    height(pct(110.)),
    backgroundImage(url(src)),
    backgroundRepeat(noRepeat),
    backgroundColor(bgColor),
    backgroundPosition(pct(50.), zero),
    backgroundSize(cover),
    animation(~duration=animDuration, ~direction=alternateReverse, ~iterationCount=infinite, animationName),
    unsafe("backgroundBlendMode", blendMode)
  ])
};


[@react.component]
let make = (~src) => {
  let bgColor = `hex("fff");
  let blendMode = "hard-light";
  let baseDuration = 1500;
  
  <div className=Styles.wrapper(~src)>
    <div className=Styles.glitch(~src, ~bgColor, ~blendMode, ~animDuration=(baseDuration + 800 ), ()) />
    <div className=Styles.glitch(~src, ~bgColor=`hex("000"), ~blendMode, ~animDuration=(baseDuration + 900 ), ()) />
    <div className=Styles.glitch(~src, ~bgColor, ~blendMode, ~animDuration=( baseDuration + 1000 ), ()) />
    <div className=Styles.glitch(~src, ~bgColor=`hex("000"), ~blendMode="overlay", ~animDuration=( baseDuration + 500 ), ()) />
  </div>
}

let default = make
