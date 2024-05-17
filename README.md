<div align="center">
    <img width="650" src="https://drive.google.com/uc?export=view&id=1Enwe0OW9wRdDQNePTdth3RHlzxgeDwnQ">
</div>

# Corewar

## Documentation en français

### L'origine du projet Corewar :
Le Corewar est un projet d'études de fin de première année à **EPITECH**. Il conclut un module appelé "*CPE*" ou en d'autres termes "*Elementary programming in C*". <br>
Dans ce dernier, le but est d'acquérir les compétences nécessaires pour pouvoir créer n'importe quel projet en C.

### Qu'est-ce que le Corewar ?
Le tournoi Corewar est un jeu dans lequel plusieurs programmes appelés "Champions" vont se battre dans une simulation virtuelle appelé "mémoire". Le dernier en vie gagne.

> Core War est un jeu de programmation de 1984 créé par D. G. Jones et A. K. Dewdney dans lequel deux ou plusieurs programmes de combat (appelés « Champions ») s'affrontent pour le contrôle d'un ordinateur virtuel. Ces programmes de combat sont écrits dans un langage assembleur abstrait appelé Redcode. Les normes pour le langage et la machine virtuelle ont été initialement définies par l'International Core Wars Society (ICWS), mais les normes ultérieures ont été déterminées par consensus communautaire.

### Quels sont les objectifs de ce projet ? 
L'objectif principal est de créer la "machine virtuelle" où vont se battre les "champions". L'importance de la machine est d'exécuter correctement les instructions de chacun en en respectant un ordre et un cycle de jeu dans un temps imparti ou jusqu'à ce qu'il n'en reste plus qu'un.

### Qui a travaillé dessus ? 
Le groupe ayant réalisé ce projet est composé de deux personnes : ***Tom Carlier*** et ***Emma Farineaux***, tout deux étudiants à **EPITECH Lille** (promo 2028).

### Comment l'installer ?
Ce programme est destiné aux systèmes UNIX. <br>
Il suffit de cloner les dépositoire (ou répositoire) avec la commande suivante : <br>
`git clone git@github.com:EpitechPromo2028/B-CPE-200-LIL-2-1-corewar-tom.carlier.git`

## Comment l'utiliser ?

### Le rôle de la machine :
Le rôle de la machine est simple, elle se doit d'executer le programme donné en paramètre. Elle doit vérifier si, **chaque tour**, les champions ont appelé l'instruction "live" (permettant de signaler que le champion est toujours en vie). <br>
Si après un certains nombres d'execution (représenté par "**NBR_LIVE**") de l'instruction "live" plusieurs processes (champions) sont en vie, alors la machine va commencé un décompte depuis un certain nombre (représenté par "**CYCLE_TO_DIE**" ) en faisant moins un autre nomrbe (représenté par "**CYCLE_DELTA**"). 

> Tout mots mis en gras signifie que la valeur peut-être changer dans le fichier avec le chemin "*include/op.h*".

L'une des particularité qui été obligatoire de notre machine est qu'elle peut-être lancé sans environnement graphique. C'est-à-dire que le programme peut être exécuté et fonctionner efficacement sans nécessiter de système d'interface utilisateur graphique (GUI).
Cela signifie que le programme peut être exécuté en ligne de commande, généralement via un terminal ou une invite de commande, sans avoir besoin d'une interface graphique comme des fenêtres, des boutons, des icônes, etc.


