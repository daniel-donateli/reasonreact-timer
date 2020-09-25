open Utils;

let updateTitle: string => unit = [%bs.raw
    {|
        function updateTitle(remaining) {
            document.title = "⏰ " + remaining + " ⏰";
        }
    |}
];

type state = {
    seconds: int,
    isTicking: bool,
};

type action =
    | Start
    | Stop
    | Reset
    | Tick;

let initialState = {
    seconds: 30,
    isTicking: false,
};

let reducer = (state, action) => {
    switch(action) {
        | Start => {...state, isTicking: true}
        | Stop => {...state, isTicking: false}
        | Reset => {
                updateTitle(formatTime(30));
                {seconds: 30, isTicking: false};
            }
        | Tick => state.isTicking && state.seconds > 0 ?
            {
                updateTitle(formatTime(state.seconds - 1));
                {...state, seconds: state.seconds - 1};
            }
            : state
    };
};