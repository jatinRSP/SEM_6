import Counter from "./Counter";

function App() {
  return (
    <>
      <h1>DATE PICKER</h1>
      <Counter label="DATE" min={1} max={31} />
      <Counter label="MONTH" min={1} max={12} />
      <Counter label="YEAR" min={2000} max={2022} />
    </>
  );
}

export default App;
