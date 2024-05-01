import React from 'react'
import { BrowserRouter, Routes, Route, NavLink } from 'react-router-dom'

import './app.css'
import Chart from './Chart';

function App() {

  // Function to generate random values for each item in the data array
  function generateRandomData() {
    const labels = ['Flour', 'Butter', 'Sugar', 'Eggs'];
    return labels.map(label => ({
      label: label,
      value: Math.floor(Math.random() * 100) + 24 // Generating random values between 100 and 400
    }));
  }

  const data1 = generateRandomData();
  const data2 = generateRandomData();
  const data3 = generateRandomData();
  const data4 = generateRandomData();

  return (


    <>
      <BrowserRouter>

        <div className='linkwrapper'>
          <NavLink to='/Croissants' className='link'> <img src="https://cdn-icons-png.flaticon.com/512/7627/7627796.png" /> Croissants</NavLink>
          <NavLink to='/Pancakes' className='link'> <img src="https://cdn-icons-png.flaticon.com/512/3009/3009894.png" /> Pancakes</NavLink>
          <NavLink to='/Cookies' className='link'> <img src="https://cdn-icons-png.flaticon.com/512/1047/1047711.png" /> Cookies</NavLink>
          <NavLink to='/Dougnuts' className='link'> <img src="https://cdn-icons-png.freepik.com/512/2821/2821785.png" /> Dougnuts</NavLink>
        </div>

        <Routes>
          <Route path='/Croissants' element={<Chart data={data1}/>} />
          <Route path='/Pancakes' element={<Chart data={data2} />} />
          <Route path='/Cookies' element={<Chart data={data3} />} />
          <Route path='/Dougnuts' element={<Chart data={data4} />} />
        </Routes>

      </BrowserRouter>
    </>
  )
}

export default App
