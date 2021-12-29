import matplotlib.pyplot as plt
import matplotlib.pyplot as plt2
file = open("data.txt", "r")
file2 = open("data2.txt", "r")
dataList = file.readlines()
dataList2 = file2.readlines()
file.close()
file2.close()
dataList = [line.rstrip() for line in dataList]
dataList2 = [line.rstrip() for line in dataList2]
dataList = [line.split() for line in dataList]
dataList2 = [line.split() for line in dataList2]
x = [float(line[0]) for line in dataList]
y = [float(line[1]) for line in dataList]
x2 = [float(line[0]) for line in dataList2]
y2 = [float(line[1]) for line in dataList2]
plt.plot(x, y,'r')
plt.plot(x, y2,'g')
plt.show()

