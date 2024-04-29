import { useState } from "react";
import React from "react";
import ReactForm from "./ReactForm";

function App() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <h1>React Hook Form</h1>
      <ReactForm />
    </div>
  );
}

export default App;
