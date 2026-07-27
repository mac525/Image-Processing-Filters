# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""


from matplotlib import pyplot as plt
import numpy as np

imageSize = (480,640)

# For raw image (without any headers)
input_file = '/Users/mac525/Work/EE Topics /EECS203/Raw images/Image-Processing-Filters/Input/cat.raw'
npimg = np.fromfile(input_file, dtype=np.uint8)
inputimg = npimg.reshape(imageSize)

noise_file = '/Users/mac525/Work/EE Topics /EECS203/Raw images/Image-Processing-Filters/Output/NoiseCat.raw'
npimg = np.fromfile(noise_file, dtype=np.uint8)
noise = npimg.reshape(imageSize)

output_file = '/Users/mac525/Work/EE Topics /EECS203/Raw images/Image-Processing-Filters/Output/cat1.raw'
npimg = np.fromfile(output_file, dtype=np.uint8)
output = npimg.reshape(imageSize)

#plot input image
plt.figure()  
plt.title("input image")
plt.imshow(inputimg, cmap='gray', vmin=0, vmax=255)
plt.show()

#plot noise image
plt.figure()  
plt.title("input + noise image")
plt.imshow(noise, cmap='gray', vmin=0, vmax=255)
plt.show()

#plot output image
plt.figure()  
plt.title("filtered image")
plt.imshow(output, cmap='gray', vmin=0, vmax=255)
plt.show()