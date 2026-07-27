#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 10 23:30:23 2023

@author: mac525
"""

import subprocess
import os

inputFile = "Input/cat.raw"
outputFile = "Output/cat1.raw"
noiseFile = "Output/NoiseCat.raw" 

run_command = "./release/ImageProcessing"

#get main path            
out = subprocess.run(["pwd"], 
                     stdout=subprocess.PIPE,
                     text=True) 
currentPath = out.stdout
(mainPath,temp) = os.path.split(currentPath)
print(out.stdout)

#run make
os.chdir(mainPath)
out = subprocess.run(["make"], 
                     stdout=subprocess.PIPE,
                     text=True) 
print(out.stdout)

#run main
out = subprocess.run([run_command,inputFile,outputFile,noiseFile], 
                     stdout=subprocess.PIPE,
                     text=True) 
print(out.stdout)               

#check output
os.chdir(mainPath + "/Output")
out = subprocess.run(["ls","-l"], 
                     stdout=subprocess.PIPE,
                     text=True) 
print(out.stdout)                     