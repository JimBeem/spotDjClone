open ReasonReact;
module Css = AppStyle;

[@react.component]
let make = () => {
  <div className=Css.app>
    <User />
    <h1> {string("Welcome to SpotDJ")} </h1>
    <LinkShare />
    <div className="current-playing">
      <p> {string("Played by userABC")} </p>
    </div>
  </div>;
};
