while(True):
  nome= str(input("Digite um Nome"))
  if(len(nome )>3):
    break
  else:
    print("Nome inv�lido. Digite novamente.")

while (True):
    idade = int(input("Digite a idade: "))
    if (0 <= idade <= 150):
      break
    else:
      print("Idade inv�lida. Digite novamente.") 
      
while(True):
  salario = float(input("Digite o Salario"))
  if(salario > 0):
    break
  else:
    print("salario inv�lido. Digite novamente.") 
    
while(True):
  sexo = str(input("Digite Sexo. (M) ou (F)").lower())
  if(sexo in ['f','m']):    
    break
  else:
    print("sexo inv�lido. Digite novamente.") 
    while(True):
  civil = str(input("Digite estado civil. (S) ou (D) ou (C) ou (V)").lower())
  if(civil in ['s','d','c','v']):    
    break
  else:
    print("sexo inv�lido. Digite novamente.") 

print(f"NOME:{nome} IDADE:{idade} SALARIO:{salario} SEXO:{sexo} ESTADO-CIVIL:{civil}")

