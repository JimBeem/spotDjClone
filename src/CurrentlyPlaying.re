open Utils;
open ReasonReact;

module Css = AppStyle;

let songImage = requireAssetURI("./img/now-playing-ex.png");
let audioWave = requireAssetURI("./img/audio-wave.png");
let like = requireAssetURI("./img/like.png");
let share = requireAssetURI("./img/share.png");

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
      <div className=Css.songImageFilter />
      <div
        className={Cn.make([
          Css.flexWrapper(~justify=`spaceAround, ~align=`center),
          Css.songInfo,
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
