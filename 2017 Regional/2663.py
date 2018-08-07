n = int(input())
clas = int(input())
v,cont,r = [],0,[]
for i in range(n):
	v.append(int(input()))
v = sorted(v,reverse=True)
uni = v[0]
for i in range(n):
	if (uni == v[i]):
		r.append(v[i])
		cont += 1
		if cont >= clas and v[i] != v[i+1]:
			break
print(cont)