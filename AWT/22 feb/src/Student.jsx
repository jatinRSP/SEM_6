import React, { useState } from "react";

function Students(props) {
  if (true) {
    let [value, setValue] = useState(0);
  }

  function HandleClick() {
    setValue(value + 1);
  }

  return (
    <div>
      <h1>Student List</h1>
      <p>Count: {value}</p>
      <p>NAME: {props.name}</p>
      <p>AGE: {props.age}</p>
      <p>STUDENt: {props.isStudent ? "YES" : "NO"}</p>
      <button onClick={HandleClick}>Click me</button>
    </div>
  );
}

export default Students;
