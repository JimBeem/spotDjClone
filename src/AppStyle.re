open Css;

let app = style([textAlign(`center)]);

let userIcon = style([width(`px(25))]);

let flexWrapper = (~justify, ~align) =>
  style([display(`flex), justifyContent(justify), alignItems(align)]);

let pageTitle = style([fontSize(`px(48)), marginBottom(`px(64))]);

let pageSubTitle =
  style([
    fontSize(`px(24)),
    marginBottom(`px(32)),
    fontWeight(`num(300)),
  ]);

/*Link Sharing*/

Emotion.backgroundImage;
