for i in range(int(input())):
	valores=list(map(int,input().split()))
	valores.sort()
	valores.append(24-sum(valores))
	if (valores[2] > 12 or valores[3] > 12):
		print("nao adequada")
	elif (valores[3] < 6):
		print("nao adequada")
	elif (valores.count(0) >= 2):
		print("nao adequada")
	else:
		print("adequada")
