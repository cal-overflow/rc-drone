# -*- coding: utf-8 -*-
"""
Created on Sat Apr 16 13:32:37 2022
@author: Spencer Dunahm
This file will generate airfoil shapes to be used in XFLR5.
Each file will have have 4 unique data point, 5 in total. Each unique point
corresponds to each point on the parallelogram.
"""
def shape2string(shape):
    outString = ""
    for x in shape:
        outString += str(x[0]) + " " + str(x[1]) + "\n"
    outString += "0 0"
    return(outString)



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


shapes = []


for a in range(ySize):
    for b in range(len(xPosHigh)):
        for c in range(len(xPosLow)):
            if xPosLow[c] >= xPosHigh[b]:
                break
            else:
                shapes.append([[0,0],[1,0],[xPosHigh[b],yPos[a]],[xPosLow[c],yPos[a]]])

        

for i in range(len(shapes)):
    f = open(fileName[i], "w")
    f.write(shape2string(shapes[i]))
    f.close()

