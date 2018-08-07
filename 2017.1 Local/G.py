for i in range(int(input())):
	valores = list(map(float,input().split()))
	media = sum(valores)/len(valores)
	var=[]
	for j in range(len(valores)):
		var.append((valores[j]-media)**2)
	desvio = (sum(var)/len(valores))**(1/2)
	print("Turma %f: media %.2f desvio %.2f" % ((i+1),media,desvio))
