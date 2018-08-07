d,l,x,f = map(int,input().split())
if (d%2 == 0 and f%2 != 0):
	l=l+(f-1)*x-f*x
elif (d%2 != 0 and f%2 == 0):
	l=l
elif (d%2 != 0 and f%2 != 0):
	l=l+f*x-(f-1)*x
else:
	l=l
print(l)