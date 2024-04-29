// import './App.css'
// import React from 'react'
// import HelloWorld from './helloworld'

// function App() {
//   return (
//     <>
//       <HelloWorld />
//       <p>gfgh</p>
//     </>
//   )
// }

// export default App

const isLoggedIn = false

const element = (
  isLoggedIn ? <h1>Welcome</h1> : <h1>Please log in</h1>

);

function App() {
  return (
    <div>
      {element}
    </div>
  );
}

export default App