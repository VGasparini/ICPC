a,op,b = input().split()
a=int(a.replace("7","0"))
b=int(b.replace("7","0"))
if (op =="+"):
	r=str(a+b)
	r=int(r.replace("7","0"))
elif (op =="x"):
	r=str(a*b)
	r=int(r.replace("7","0"))
print(r)