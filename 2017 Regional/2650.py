n = int(input())
clas = int(input())
v = []
for i in range(n):
	v.append(int(input()))
v = sorted(v,reverse = True)
print(v)