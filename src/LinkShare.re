open ReasonReact;
open BsReactstrap;
open Css;

module Css = AppStyle;

type action =
  | Toggle;

type state = {isDropdownOpen: bool};

let linkSharing = style([marginBottom(`px(64))]);

let shareLinkURL =
  style([
    border(`px(0), `none, `hex("ffffff")),
    borderBottom(`px(1), `solid, `hex("cfcfcf")),
    padding2(~v=`px(0), ~h=`px(8)),
    width(`px(280)),
  ]);

let subInfo =
  style([
    fontSize(`px(14)),
    color(`hex("a2a2a2")),
    padding2(~v=`px(0), ~h=`px(8)),
    selector(
      "#stop-btn",
      [
        color(`hex("ff4e4e")),
        margin2(~v=`px(0), ~h=`px(16)),
        textDecoration(`underline),
        selector(":hover", [cursor(`pointer), color(red)]),
      ],
    ),
  ]);

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

  <div className=linkSharing>
    <p className=Css.pageSubTitle>
      {string("Share the following link to invite people to your music")}
    </p>
    <div
      style={ReactDOMRe.Style.make(~width="fit-content", ~margin="auto", ())}>
      <div className={Css.flexWrapper(~justify=`center, ~align=`flexEnd)} />
      <input
        className=shareLinkURL
        value="www.example.com/?userId"
        readOnly=true
      />
      <Dropdown
        isOpen={state.isDropdownOpen} toggle={() => action(Toggle)} size="sm">
        <DropdownToggle caret=true> {string("Share")} </DropdownToggle>
        <DropdownMenu>
          <DropdownItem> {string("Facebook")} </DropdownItem>
          <DropdownItem> {string("Twitter")} </DropdownItem>
          <DropdownItem> {string("Copy URL")} </DropdownItem>
        </DropdownMenu>
      </Dropdown>
      <div
        className={Cn.make([
          Css.flexWrapper(~justify=`flexStart, ~align=`flexStart),
          subInfo,
        ])}>
        <p> <i> {string("240 Listners")} </i> </p>
        <a id="stop-btn"> {string("Stop Sharing")} </a>
      </div>
    </div>
  </div>;
};
