open Utils;
open BsReactstrap;
module Css = AppStyle;

type action =
  | Toggle;

type state = {isDropdownOpen: bool};

let userIcon = requireAssetURI("./img/user.png");

[@react.component]
let make = () => {
  let (state, action) =
    React.useReducer(
      (state: state, action) =>
        switch (action) {
        | Toggle => {isDropdownOpen: !state.isDropdownOpen}
        },
      {isDropdownOpen: false},
    );
  <header className=Css.flexWrapperRightAlign>
    <div style={ReactDOMRe.Style.make(~width="100px", ())}>
      <Dropdown isOpen={state.isDropdownOpen} toggle={() => action(Toggle)}>
        <DropdownToggle
          caret=true
          tag="div"
          className={Cn.make([
            Css.flexWrapperRightAlign,
            Css.userAccountWrapper,
          ])}>
          <img className=Css.userIcon src=userIcon alt="user icon" />
          <p style={ReactDOMRe.Style.make(~margin="0px", ())}>
            {ReasonReact.string("userABC")}
          </p>
        </DropdownToggle>
        <DropdownMenu right=true>
          <DropdownItem> {ReasonReact.string("Sign Out")} </DropdownItem>
        </DropdownMenu>
      </Dropdown>
    </div>
  </header>;
};
