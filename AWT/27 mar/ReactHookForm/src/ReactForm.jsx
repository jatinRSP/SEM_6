import { useForm } from "react-hook-form";
import React from "react";

// create form component

function ReactForm() {
  // create form object
  const {
    register,
    handleSubmit,
    formState: { errors },
  } = useForm();

  // create submit function
  const onSubmit = (data) => {
    console.log(data);
  };

  return (
    <form onSubmit={handleSubmit(onSubmit)}>
      <input
        type="text"
        placeholder="Enter your name"
        {...register("name", { required: true })}
      />
      {errors.name && <p>This field is required</p>}

      <input
        type="number"
        placeholder="Enter your age"
        {...register("age", { required: true })}
      />
      {errors.age && <p>This field is required</p>}

      <input
        type="password"
        placeholder="Enter your password"
        {...register("password", { required: true, minLength: 6 })}
      />
      <button type="submit">Submit</button>
    </form>
  );
}

export default ReactForm;
