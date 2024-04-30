def ActivationFunction(y_in): # Step Function
    if y_in > 0:
        return 1
    else:
        return -1
    
# Other activation function equation
# def ActivationFunction(y_in): # Sigmoid Function
#     return 1/(1 + math.exp(-y_in))

# def ActivationFunction(y_in): # Tanh Function
#     return (math.exp(y_in) - math.exp(-y_in))/(math.exp(y_in) + math.exp(-y_in))

# def ActivationFunction(y_in): # ReLU Function
#     if y_in > 0:
#         return y_in
#     else:
#         return 0

# def ActivationFunction(y_in): # Leaky ReLU Function
#     if y_in > 0:
#         return y_in
#     else:
#         return 0.01*y_in

# def ActivationFunction(y_in): # Softmax Function
#     return math.exp(y_in)/sum(math.exp(y_in))


x1 = [1,1,-1,-1]
x2 = [1,-1,1,-1]
t = [1,-1,-1,-1]

def perceptron(x1, x2, learning_rate=1, epochs=2):
    w1 = 0
    w2 = 0
    b = 0

    for epoch in range(epochs):
        for i in range(len(x1)):
            y_in = x1[i]*w1 + x2[i]*w2 + b
            y = ActivationFunction(y_in)

            if y != t[i]:
                w1 = w1 + learning_rate*t[i]*x1[i]
                w2 = w2 + learning_rate*t[i]*x2[i]
                b = b + learning_rate*t[i]

    return w1, w2, b

weights = perceptron(x1, x2)
print(weights)
