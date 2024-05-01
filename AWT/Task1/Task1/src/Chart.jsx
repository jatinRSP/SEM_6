import React from 'react';
import './Chart.css';

const Chart = ({ data }) => {
  // Calculate the maximum value in the data array
  const maxValue = Math.max(...data.map(item => item.value));

  return (
    <div className="bar-chart">
      {data.map((item, index) => (
        <div key={index} className="bar">
          <div
            className="bar-fill"
            style={{ height: `${(item.value / maxValue) * 100}%` }}
          ></div>
          <div className="bar-label">{item.label}</div>
        </div>
      ))}
    </div>
  );
};

export default Chart;
