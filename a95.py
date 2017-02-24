n,m = map(int,input().split())
cars = []

for i in range(n):
	cars.append(input().split())

def CarsRank(car):
	return (car[0],car[1])
def TimeRank(timeLine):
	return timeLine[0]

cars.sort(key=CarsRank)

dic = {}
timeLine = []
maxTime = 0
maxTimeCar = []

def toNum(time):
	return int(time[:2])*3600+int(time[3:5])*60+int(time[6:])

for i in range(n-1):
	if(cars[i][2]=='in' and cars[i+1][2]=='out'):
		a = toNum(cars[i][1])
		b = toNum(cars[i+1][1])
		timeLine.append([a,b])
		if(dic.get(cars[i][0])!=None):
			dic[cars[i][0]] = dic.get(cars[i][0])+(b-a)
		else:
			dic[cars[i][0]] = b-a

		if(dic[cars[i][0]]>=maxTime):
			if(dic[cars[i][0]]==maxTime):
				maxTimeCar.append(cars[i][0])
			else:
				maxTimeCar.clear()
				maxTimeCar.append(cars[i][0])
				maxTime=dic[cars[i][0]]

timeLine.sort(key=TimeRank)
ans = [0]*m
for i in range(m):
	num = input()
	check = toNum(num)
	for ele in timeLine:
		if(ele[0]>check):
			break
		if(check>=ele[0] and check<ele[1]):
			ans[i] += 1

for ele in ans:
	print(ele)
maxTimeCar.sort()
for ele in maxTimeCar:
	print(ele,end=' ')
print("%02d:%02d:%02d" % (maxTime/3600,maxTime%3600/60,maxTime%60))
