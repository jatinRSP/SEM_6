import React, { useState, useEffect } from "react";

const Counter = ({ label, min, max }) => {
  const [count, setCount] = useState(min);

  useEffect(() => {
    console.log("useEffect");
    if (count < min) {
      setCount(min);
    }
    if (count > max) {
      setCount(max);
    }
  }, [count, min, max]);
  return (
    <div>
      <h1>{label}</h1>
      <h1>{count}</h1>
      <button onClick={() => setCount(count < min + 1 ? min : count - 1)}>
        Decrement
      </button>
      <button onClick={() => setCount(count > max - 1 ? max : count + 1)}>
        Increment
      </button>
      <button onClick={() => setCount(min)}>Reset</button>
    </div>
  );
};

export default Counter;
