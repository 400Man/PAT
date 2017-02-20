import numpy as np
import time
import os

# ('Date',[Solved problem])
Finished_25 = [ ('2-16',[(60,"AC")]),
				('2-17',[(39,23),(71,"AC"),(63,21),(47,18)]),

				('2-19',[]),
				('2-20',[],),
				('2-21',[],),
				('2-22',[],),
				('2-23',[],),
				('2-24',[],)
			  ]

Finished_30 = []

# 章节，题号
Que_25 = [(3.1,2),(3.1,9),(3.2,6),(3.2,36),(3.6,82),   
		  (4.1,62),(4.1,12),(4.1,16),(4.1,25),(4.1,28),(4.1,55),(4.1,75),(4.1,83),  
		  (4.2,48),(4.4,70),(4.4,33),(4.4,37),(4.4,67), 
		  (4.5,10),(4.5,44),(4.5,48),
		  (4.6,85),(4.6,89),(4.6,25),(4.6,48),(4.7,93),(4.7,101),
		  (5.4,78),(5.5,59),(5.6,24),

		  ]

Que_30 = [(4.1,80),(4.1,95),(4.4,38),(5.1,49),
		  (6.4,22)
		 ]



def Exam(n):
	if(n=='2'):
		pick_1 = np.random.randint(len(Que_25))
		pick_2 = np.random.randint(len(Que_30))
		print("\nPORBLEM SET: \n\n 1.A1%03d - 25 - %.1f\n 2.A1%03d - 30 - %.1f\n" % (Que_25[pick_1][1],Que_25[pick_1][0],Que_30[pick_2][1],Que_30[pick_2][0]))
		print("The Exam will begin in 3:00 and finished in 5:00.\n")
		score = input('Your score: ')
		score = float(score)*100/55
	else:
		pick = np.random.randint(len(Que_25),size=2)
		print("\nPROBLEM SET: \n\n 1.A1%03d - 25 - %.1f\n 2.A1%03d - 25 - %.1f\n" % (Que_25[pick[0]][1],Que_25[pick[0]][0],Que_25[pick[1]][1],Que_25[pick[1]][0]))
		print("The Exam will begin in 3:00 and finished in 4:30.\n")
		score = input('Your score: ')
		score = float(score)*100/50


	localtime = time.localtime(time.time())
	print("\n2017-%d-%d %02d:%02d Your Final Score: %d\n" % (localtime[1],localtime[2],localtime[3],localtime[4],score))
	return None
	


n=input('\nHow many hours do you have for exam: ')
os.system('cls' if os.name == 'nt' else 'clear')
Exam(n)











