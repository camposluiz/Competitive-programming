hipotese = True

while True:
    linha = input().split(' ')

    if linha[0] == "0":
        break

    if hipotese:
        maior = linha[0]
        hipotese = False
        
    len_ = len(linha);    
    for i, e in enumerate(linha):
        if len(e) >= len(maior):
            maior = e
        
        if i < len_ - 1:
            print(len(e), end='-')
        else:
            print(len(e))
        
print('\nThe biggest word: {}'.format(maior))
