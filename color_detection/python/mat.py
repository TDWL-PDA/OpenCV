#! /usr/bin/python

def help():
	print("Help Function")


#import the necessary packages
import numpy as np
import argparse
import cv2

#help()

#Construct the argument parser
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", help = "path to the image")
args = vars(ap.parse_args())

#load the image
image = cv2.imread(args["image"])

##INSERT REST OF PYTHON CODE HERE
