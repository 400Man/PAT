with open('1.txt') as f:
	print(sum(1 for _ in f))
	print(list(f))