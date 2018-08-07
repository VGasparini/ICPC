m,p,j,x = input().split()
m,p,j,x = int(m),float(p),float(j),int(x)

meses = 0
a=1

while (a!=0):
    doa = m*(p/100)
    m -= doa
    juros = m*(j/100)
    if(juros >= x):
    	a=1
    	meses += 1
    else:
    	a=0
print(meses)