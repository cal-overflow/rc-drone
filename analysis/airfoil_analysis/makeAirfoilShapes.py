# -*- coding: utf-8 -*-
import math
"""
Created on Sat Apr 16 13:32:37 2022
@author: Spencer Dunahm
This file will generate airfoil shapes to be used in XFLR5.
Each file will have have 4 unique data point, 5 in total. Each unique point 
corresponds to each point on the parallelogram.
"""
numberOfAirfoils = 25

#defines all x, y points for airfoil creation  
yPos = [.125,.25,.375,.5]
xPosLow = [.125,.25,.375,.5,.625]
xPosHigh = [.25,.375,.5,.625,.75]
ySize = len(yPos)
xSize = int((len(xPosLow)*(len(xPosLow)+1))/2)
numberOfAirfoils = xSize * ySize

fileName = []
for x in range(numberOfAirfoils):
    fileName.append("airfoil"+str(x+1)+".dat")

for x in fileName:
    print(x)
#index 0 is x position, index 1 is y position
points = []

#creates first shape
points.append([0,0])
points.append([1,0])
points.append([xPosLow[0],yPos[0]])
points.append([xPosHigh[4],yPos[0]])


shapes = []
i = 1
while i < numberOfAirfoils:
    #work goes here
    i += 1


for x in shape:
    print(x)
