#!/usr/bin/env python
# coding: utf-8

# In[1]:


import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
from tensorflow.keras.models import Sequential
import numpy as np
import keras_contrib
import os
from tensorflow.keras.models import load_model
import sys
import imageio
os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID"
os.environ['CUDA_VISIBLE_DEVICES'] = "-1"


# In[ ]:





# In[ ]:





# In[2]:


IMG_WIDTH = 256
IMG_HEIGHT = 256
def load(image_file):
    input_image = tf.io.read_file(image_file)
    input_image = tf.image.decode_jpeg(input_image)
    input_image = tf.cast(input_image, tf.float32)
    input_image=tf.image.resize(input_image,[256,256])
    input_image=tf.reshape(input_image,(1,256,256,3))
    return input_image
def normalize(input_image):
    input_image = (input_image / 127.5) - 1
    return input_image
def resize(input_image,  height, width):
    input_image = tf.image.resize(input_image, [height, width],
                                method=tf.image.ResizeMethod.NEAREST_NEIGHBOR)
    return input_image
def load_image_test(image_file):
    input_image = load(image_file)
    input_image = resize(input_image,IMG_HEIGHT, IMG_WIDTH)
    input_image= normalize(input_image)
    return input_image
def generate_images(model, test_input):
    prediction = model(test_input, training=True)
    return prediction[0]
def main(argv):
    generator =load_model(argv[1])
    image=load_image_test(argv[2])
    result=generate_images(generator, image)*0.5+0.5
    result=tf.image.resize(result,[400,400])
    imageio.imsave('./'+argv[3],result)
if __name__ == "__main__":
    main(sys.argv)


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




