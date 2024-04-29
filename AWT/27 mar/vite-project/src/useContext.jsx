import { useState, createContext, useContext } from "react";

const MyContext = createContext();

function useContext() {
  const [user, setUser] = useState({ name: "Jatin", age: 19 });

  return <MyContext.Provider value={{ user, setUser }}></MyContext.Provider>;
}

export default useContext;
