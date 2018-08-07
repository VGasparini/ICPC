for i in range(int(input())):
	r = list(map(int,input().split()))
	a = r[0]
	b = r[4]
	c = r[8]
	if ((r[1]==((a+c)*2)%10) and (r[2]==(3*b)%10) and (r[3]==(a+b)%10) and (r[5]==(4*c)%10) and (r[5]==(8*a)%10) and (r[7]==(a+b+c)%10)):
		print("SIM")
	else:
		print("NAO")
