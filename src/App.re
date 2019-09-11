open ReasonReact;
module Css = AppStyle;

[@react.component]
let make = () => {
  <div className=Css.app>
    <User />
    <h1 className=Css.pageTitle> {string("Welcome to SpotDJ")} </h1>
    <LinkShare />
    <CurrentlyPlaying />
  </div>;
};
