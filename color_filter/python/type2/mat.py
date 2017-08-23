#! /usr/bin/python

def help():
##	print("Before running program type: workon cv")
	print("Then open up a python environment to run this program.")
	print("To open up an environment and run it type:")
	print("python program_name.py")
	print("")
	print("The purpose of this program is to detect the color red in an image and then highlight it with a green box.")
#import the necessary packages
import numpy as np
import argparse
import cv2

help()

#construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", help = "path to the image")
args = vars(ap.parse_args())

#load the image
image = cv2.imread(args["image"])

#define the list of boundries
boundries = [
	#([17, 15, 100], [50, 56, 200])
	([20, 20, 100], [50, 56, 255])
##	([86, 31, 4], [220, 88, 50]),
##	([25, 146, 190], [62, 174, 250]),
##	([103, 86, 65], [145, 133, 128])
]

#loop over the boundries
for (lower, upper) in boundries:
#create NumPy arrays from the boundries
	lower = np.array(lower, dtype = "uint8")
	upper = np.array(upper, dtype = "uint8")

#find the colors within the specified boundries and apply the mask
mask = cv2.inRange(image, lower, upper)
output = cv2.bitwise_and(image, image, mask = mask)

#show the images
cv2.imshow("images", np.hstack([image, output]))
cv2.waitKey(0)
