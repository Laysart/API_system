# Projet Api_system 
#### Mathis Brionne, Tom Larnicol, Romain Sauvaget, Cécile Vidal 

## TEST sur une raspberry
### Pour ce connecter :

ssh : `ssh -p 30 pi@78.197.34.64`   

### Pour copier ses .c sur la raspberry : 

scp : `scp -p 30 /chemin/main.c pi@78.197.34.64:/home/pi/API` commande pour windows
scp : `scp -P 30 /chemin/main.c pi@78.197.34.64:/home/pi/API` commande pour Linux

### Pour compiller **Sur la Raspberry** :

gcc : gcc -Wall -o main.c Monprog
