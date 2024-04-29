import numpy as np

# Get x and y vector randomly



class perceptron:
    def __init__(self, n):
        self.weights = np.zeros(n)
        self.bias = 0
        self.learningRate = 0.1
        
    def predict(self, inputs):
        summation = np.dot(inputs, self.weights) + self.bias
        if summation > 0:
            activation = 1
        else:
            activation = 0
        return activation
    
    def train(self, inputs, target):
        prediction = self.predict(inputs)
        error = target - prediction
        self.weights += self.learningRate * error * inputs
        self.bias += self.learningRate * error

p = perceptron(2)
inputs = np.array([1, 1])
print(p.predict(inputs))
p.train(inputs, 1)
print(p.predict(inputs))
inputs = np.array([0, 1])
print(p.predict(inputs))
p.train(inputs, 1)
print(p.predict(inputs))