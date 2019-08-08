l = []

l += [input()]
l += [input()]
l += [input()]

for i in l:
	for u in range(len(i)):
		if i[u] == '=':
			for j in i[u+1:]:
				if j != '.':
					print(j)
					exit()
			break

print('You shall pass!!!')