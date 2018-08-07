import itertools
n,m,k = map(int,input().split())
#red=1
#hot=2
#chili=3
#peppers=4
grid=[range(n),range(m)]
print(grid)
pontos=[]
j = 1
for i in range(k):
	j = i + 1
	if (j > 4):
		j = 1
for i in range(k):
    jogada,pos = input().split()
    if (jogada == "L"):
        for l in range(m):
            grid[int(pos)-1][l]=j
    else:
        for l in range(n):
            grid[l][int(pos)-1]=j
    j += 1
    if (j > 4):
    	j = 1
pontos = [0,0,0,0]
grid = list(itertools.chain.from_iterable(grid))
for j in range(4):
    pontos[j] = grid.count(j+1)
print("R{} H{} C{} P{}".format(pontos[0],pontos[1],pontos[2],pontos[3]))