open ReasonReact;
open BsReactstrap;
module Css = AppStyle;
type action =
  | Toggle;

type state = {isDropdownOpen: bool};

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
  <div className=Css.linkSharing>
    <p className=Css.pageSubTitle>
      {string("Share the following link to invite people to your music")}
    </p>
    <div
      style={ReactDOMRe.Style.make(~width="fit-content", ~margin="auto", ())}>
      <div className={Css.flexWrapper(~justify=`center)} />
      <input
        className=Css.shareLinkURL
        value="www.example.com/?userId"
        readOnly=true
      />
      <Dropdown
        isOpen={state.isDropdownOpen} toggle={() => action(Toggle)} size="sm">
        <DropdownToggle caret=true> {string("Share")} </DropdownToggle>
        <DropdownMenu right=true>
          <DropdownItem> {string("Facebook")} </DropdownItem>
          <DropdownItem> {string("Twitter")} </DropdownItem>
          <DropdownItem> {string("Copy URL")} </DropdownItem>
        </DropdownMenu>
      </Dropdown>
      <div
        className={Cn.make([
          Css.flexWrapper(~justify=`flexStart),
          Css.subInfo,
        ])}>
        <p> <i> {string("240 Listners")} </i> </p>
        <a id="stop-btn"> {string("Stop Sharing")} </a>
      </div>
    </div>
  </div>;
};
