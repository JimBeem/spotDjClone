open Utils;
open ReasonReact;
open Css;

module Css = AppStyle;

let songImage = requireAssetURI("./img/now-playing-ex.png");
let audioWave = requireAssetURI("./img/audio-wave.png");
let like = requireAssetURI("./img/like.png");
let share = requireAssetURI("./img/share.png");

let songInfo =
  style([
    alignItems(`center),
    width(`percent(100.)),
    position(`absolute),
    bottom(`px(0)),
    padding(`px(16)),
    color(`hex("ffffff")),
    selector(".audio-wave", [width(`px(48))]),
    selector(
      ".action-btn-circle",
      [
        width(`px(32)),
        border(`px(2), `solid, `hex("ffffff")),
        borderRadius(`percent(50.)),
        padding(`px(4)),
        selector(
          ":hover",
          [cursor(`pointer), backgroundColor(`hex("525252"))],
        ),
      ],
    ),
    selector(".song-name", [fontSize(`px(24)), marginBottom(`px(0))]),
    selector(".singer-name", [fontSize(`px(14)), marginBottom(`px(0))]),
  ]);

let songImageFilter =
  style([
    width(`percent(100.)),
    height(`percent(100.)),
    position(`absolute),
    top(`px(0)),
    backgroundImage(
      `linearGradient((
        `deg(-180.),
        [
          (`zero, `rgba((255, 255, 255, 0.00))),
          (`px(85), `hex("000000")),
        ],
      )),
    ),
  ]);

[@react.component]
let make = () => {
  <div className="current-playing">
    <div
      style={ReactDOMRe.Style.make(
        ~width="300px",
        ~position="relative",
        ~margin="auto",
        (),
      )}>
      <img
        style={ReactDOMRe.Style.make(~width="100%", ())}
        src=songImage
        alt="Song Image"
      />
      <div className=songImageFilter />
      <div
        className={Cn.make([
          Css.flexWrapper(~justify=`spaceAround, ~align=`center),
          songInfo,
        ])}>
        <img className="audio-wave" src=audioWave alt="Audio Wave" />
        <div>
          <h3 className="song-name"> {string("Song Name")} </h3>
          <p className="singer-name"> {string("Author Name")} </p>
        </div>
        <img className="action-btn-circle" src=like alt="Like Icon" />
        <img className="action-btn-circle" src=share alt="Share Icon" />
      </div>
    </div>
    <p> {string("Played by userABC")} </p>
  </div>;
};
