l,c,x,y = map(int,input().split())
if (x%2 == 0 and y%2 == 0):
	print("Direita")
elif (x%2 == 0 and y%2 != 0):
	print("Esquerda")
elif (x%2 != 0 and y%2 == 0):
	print("Esquerda")
else:
	print("Direita")