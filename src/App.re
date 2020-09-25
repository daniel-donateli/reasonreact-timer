open State;

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer(reducer, initialState);
    React.useEffect0(() => {
        let timerId = Js.Global.setInterval(() => dispatch(Tick), 1000);

        Some(() => Js.Global.clearInterval(timerId));
    });

    <div className="container">
        <div className="timer">
            <Timer seconds={state.seconds}/>
            <div className="buttons">
                { state.isTicking ? 
                <button onClick={_event => dispatch(Stop)}>{"Stop" |> React.string}</button>
                :<button onClick={_event => dispatch(Start)}>{"Start" |> React.string}</button>
                }
                <button onClick={_event => dispatch(Reset)}>{"Reset" |> React.string}</button>
            </div>
        </div>
    </div>;
};