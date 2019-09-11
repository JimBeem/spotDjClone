open Css;

let app = style([textAlign(`center)]);

let userIcon = style([width(`px(25))]);

let flexWrapper = (~justify) =>
  style([display(`flex), justifyContent(justify)]);

let flexWrapperRightAlign =
  style([display(`flex), alignItems(`center), justifyContent(`flexEnd)]);

let pageTitle = style([fontSize(`px(48)), marginBottom(`px(64))]);

let pageSubTitle =
  style([
    fontSize(`px(24)),
    marginBottom(`px(32)),
    fontWeight(`num(300)),
  ]);

/*User Account*/
let userAccountWrapper =
  style([
    padding4(~top=`px(16), ~right=`px(24), ~bottom=`px(0), ~left=`px(24)),
  ]);

/*Link Sharing*/
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
