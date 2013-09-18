-- Configuration script
-- Szymon Jab³oñski

-- configuration data

resolutionWidth = 1024
resolutionHeight = 768
minVert = 100
maxVert = 100000
inputName = "Images/test2.jpg"

-- communication with Engine

Config:setInput(inputName)
Config:setWidth(resolutionWidth)
Config:setHeight(resolutionHeight)
Config:setMinVert(minVert)
Config:setMaxVert(maxVert)