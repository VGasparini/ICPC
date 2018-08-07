for i in range(int(input())):
	conjunto = list(map(int,input().split()))
	print("Conjunto: {} {} {}".format(conjunto[0],conjunto[1],conjunto[2]))
	for j in range(conjunto[2]):
		if (conjunto[0] > conjunto[1]):
			conjunto[0] = int(conjunto[0]/2)
		else:
			conjunto[1] = int(conjunto[1]/2)
	del conjunto[2]
	conjunto.sort(reverse=True)
	print(conjunto[0],conjunto[1])
	print()
