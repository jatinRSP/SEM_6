import React from "react";
import Students from "./Student";

function App() {
  return (
    <>
      <Students name="John" age="20" isStudent={true} />
      <Students name="Doe" age="22" isStudent={false} />
    </>
  );
}

export default App;
