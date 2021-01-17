# cook your dish here
N = int(input())

i = 0
while i < N:
    linha = set(input().split(' '))
    compras = list(linha)
    compras.sort()
    
    len_ = len(compras)
    for j, e in enumerate(compras):

        if j < len_ - 1:
            print(e, end=' ')
        else:
            print(e)
            
    i += 1
    