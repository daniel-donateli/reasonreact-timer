open Utils;

[@react.component]
let make = (~seconds) => {
    <p>{seconds |> formatTime |> ReasonReact.string}</p>;
};