n = int(input())
for _ in range(n):
	fodac = input()
	vals = [int(i) for i in input().split()]
	s = vals[0]*3

	for i in vals[1:]:
		if(s<i+1):
			s = i+1
	if(s%2):
		s+=1
	print(s)	