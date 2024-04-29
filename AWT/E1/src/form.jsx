import React, { useState } from "react";

function LoginForm(props) {
  let [status, setStatus] = useState(0);
  return (
    <>
      <form>
        <label>USERNAME: </label>
        <input id="username" type="text" />
        <br />
        <label>PASSWORD: </label>
        <input id="password" type="password" />

        <br />
        <br />

        <button type="submit" onClick={() => setStatus(true)}>
          Submit
        </button>

        <br />

        <h1>STATUS: {status ? "SUCESSFUL" : "FUCKKKKKK"}</h1>
      </form>
    </>
  );
}

function 

export default LoginForm;
