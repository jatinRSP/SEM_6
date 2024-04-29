function Student (props) {
    return (
        <div>
            <P>Name: {props.name}</P>
            <p>Roll No: {props.roll}</p>
            <p>Student: {props.isStudent}</p>
        </div>
    );
}

export default Student;