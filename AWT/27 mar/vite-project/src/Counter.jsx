import React from "react";
const initialState = { count: 0 };

function reducer(state, action) {
  switch (action.type) {
    case "increment":
      return { count: state.count + 1 };
    case "decrement":
      return { count: state.count - 1 };
    default:
      throw new Error();
  }
}

function Counter() {
  const [state, dispatch] = React.useReducer(reducer, initialState);
  return (
    <>
      Count: {state.count}
      <br />
      <br />
      <button onClick={() => dispatch({ type: "decrement" })}>GHATAO</button>
      <br />
      <br />
      <button onClick={() => dispatch({ type: "increment" })}>BADHAO</button>
    </>
  );
}

export default Counter;
