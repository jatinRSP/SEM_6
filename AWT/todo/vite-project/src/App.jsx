import { useState } from "react";
import Header from "./Components/Heade1r";
import TodoItem from "./Components/TodoItem";
import Button from "./Components/Button";
import "./App.css";

function App() {
  const [count, setCount] = useState(0);

  return (
    <div className="todo-container">
      <Header />
      <TodoItem />
      <Button></Button>
    </div>
  );
}

export default App;
