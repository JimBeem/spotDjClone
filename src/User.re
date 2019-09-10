open Utils;

let userIcon = requireAssetURI("./img/user.png");

[@react.component]
let make = () => {
  <div>
    <img src=userIcon alt="user icon" />
    <p> {ReasonReact.string("userABC")} </p>
  </div>;
};
