#  Import

import tensorflow as tf
import keras
import matplotlib.pyplot as plt
mnist = tf.keras.datasets.mnist
Sequential = tf.keras.models.Sequential
from keras import layers,models
to_categorical = tf.keras.utils.to_categorical

##################################################################################

# data preparation and importing the data
(x_train, y_train), (x_test, y_test) = mnist.load_data() #We have partitioned the data into training and testing sets

# Exploring the data
print(x_train.shape) # 60000 images with 28x28 pixels
print(x_test.shape) # 10000 images with 28x28 pixels
print(y_train.shape) # 60000 labels
print(y_test.shape) # 10000 labels

index_image = 5555
print(y_train[index_image])
plt.imshow(x_train[index_image], cmap='Greys')
plt.show()

##################################################################################

# Data preprocessing
# 4d form as input (size of data, 28, 28, 1)

x_train = x_train.reshape(x_train.shape[0], 28, 28, 1)
x_test = x_test.reshape(x_test.shape[0], 28, 28, 1)

input_shape = (28, 28, 1)

# Converting data in form of float32
x_train = x_train.astype('float32')
x_test = x_test.astype('float32')

# Normalize data in range 0 to 1

x_train /= 255
x_test /= 255

##################################################################################

#  Creating the model

# instantiate model
model = Sequential()

# add a convolutional layer
model.add(layers.Conv2D(6, kernel_size=(5,5), strides=(1,1), activation='tanh', input_shape=(28,28,1), padding='same'))

# add a average pooling layer
model.add(layers.AveragePooling2D(pool_size=(2,2), strides=(1,1), padding='valid'))

# add a convolutional layer
model.add(layers.Conv2D(16, kernel_size=(5,5), strides=(1,1), activation='tanh', padding='valid'))

# add a average pooling layer
model.add(layers.AveragePooling2D(pool_size=(2,2), strides=(2,2), padding='valid'))

# add fully connected layers
model.add(layers.Conv2D(120, kernel_size=(5,5), strides=(1,1), activation='tanh', padding='same'))

# add flatten layer
model.add(layers.Flatten())

# add dense layer
model.add(layers.Dense(84, activation='tanh'))

# add output layer
model.add(layers.Dense(10, activation='softmax'))

# compile the model
model.compile(loss=keras.losses.categorical_crossentropy, optimizer='SGD', metrics=['accuracy'])

model.summary()

##################################################################################

# Training the model

# convert labels to one-hot encoding
y_train = to_categorical(y_train)
y_test = to_categorical(y_test)

# train the model
model.fit(x_train, y_train, batch_size=128, epochs=20, validation_data=(x_test, y_test))

##################################################################################

# plotting the accuracy

f, ax = plt.subplots()
ax.plot([None] + hist.history['accuracy'], 'o-')
ax.plot([None] + hist.history['val_accuracy'], 'x-')

# Plot legend and use the best location automatically: loc = 0.
ax.legend(['Train acc', 'Validation acc'], loc = 0)
ax.set_title('Training/Validation acc per Epoch')
ax.set_xlabel('Epoch')
ax.set_ylabel('acc')

plt.show()

##################################################################################

# plotting the loss

f, ax = plt.subplots()
ax.plot([None] + hist.history['loss'], 'o-')
ax.plot([None] + hist.history['val_loss'], 'x-')

# Plot legend and use the best location automatically: loc = 0.
ax.legend(['Train Loss', 'Validation Loss'], loc = 0)
ax.set_title('Training/Validation Loss per Epoch')
ax.set_xlabel('Epoch')
ax.set_ylabel('Loss')

plt.show()

##################################################################################