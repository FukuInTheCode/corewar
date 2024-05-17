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
Le pdf d'EPITECH ne vous donnera que le -h comme vrai repère de ce qu'il faut récupérer mais nous sommes là pour arranger cela :)

Avant tout, il vous faudra faire la commande `Make` pour obtenir le binaire.

Tom vous explique tout ça très rapidement et simplement :

> Pour utiliser le COREWAR, il faut tout d'abord avoir des .cor valides puis les passer en paramètres du binaire corewar comme ceci `./corewar champ1.cor champ2.cor ...` il faut avoir un minimum de 2 champions et un maximum de 4 champions. <br>
> Le combat commencera par la suite et vous serez notifié à chaque instruction LIVE, à la mort d'un champion ou à la fin du combat. <br>
> Si vous ne spécifiez aucun autres paramètres, les champions seront mis à equidistance dans la zone de combat. <br>
> Il y a quelques paramètres possibles: <br>
> -dump n -> si vous souhaitez voir la zone de combat apres un certains nombres n de cycle(s) <br>
> -a n -> si vous souhaitez spécifier la position de départ du champion <br>
> -n -> si vous souhaitez spécifier un id à votre champion <br>


### Les instructions possible: 
<div align="center">
<table>
    <thead>
        <tr>
            <th>"Mnemonic"</th>
            <th>Paramètres/Effets</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0x01 (live)</td>
            <td>Il prend un paramètre : 4 bytes représentant le numéro du joueur. Il indique que le joueur est en vie. </td>
        </tr>
        <tr>
            <td>0x02 (ld)</td>
            <td>Il prend 2 paramètres. Il met la valeur du premier paramètre dans le second et celui-ci se doit d'être un registre (non un PC). Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x03 (st)</td>
            <td>Il prend 2 paramètres. Il garde la valeur du premier paramètre (qui est un registre) dans le second (qui peut-être soit un registre, soit un numéro).</td>
        </tr>
        <tr>
            <td>0x04 (add)</td>
            <td>Il prend 3 paramètres, tous des registres. Il ajoute le contenu des deux premiers et met le résultat de l'addition dans le troisième. Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x05 (sub)</td> 
            <td>Similaire à "add" mais avec une soustraction.</td>
        </tr>
        <tr>
            <td>0x06 (and)</td>
            <td>Il prend trois paramètres. Il effectue un "AND" entre les deux premiers paramètres et met le résultat dans le troisième (devant être un registre). Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x07 (or)</td>
            <td>Similaire à "and" mais en effectuant "OR".</td>
        </tr>
        <tr>
            <td>0x08 (xor)</td>
            <td>Similaire à "and" mais en effectuant "XOR".</td>
        </tr>
        <tr>
            <td>0x09 (zjmp)</td>
            <td>Il prend un paramètre devant être un index. Il saute jusqu'à cet index si le "carry" vaut 1. Sinon il ne fait rien.</td>
        </tr>
        <tr>
            <td>0x0a (ldi)</td>
            <td>Il prend trois paramètres. Les deux premiers doivent être soit des index, soit des registres. Le troisième doit être un registre. Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x0b (sti)</td>
            <td>Il prend trois paramètres. Le premier doit être un registre. Les deux autres peuvent être un index ou un registre.</td>
        </tr>
        <tr>
            <td>0x0c (fork)</td>
            <td>Il prend un paramètre qui est un index. Il cree un nouveau programme héritant des états du parents.</td>
        </tr>
        <tr>
            <td>0x0d (lld)</td>
            <td>Similaire à "ld" mais sans le "% IDX_MOD". Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x0e (lldi)</td>
            <td>Similaire à "ldi" mais sans le "% IDX_MOD". Cette opération modifie le "carry".</td>
        </tr>
        <tr>
            <td>0x0f (lfork)</td>
            <td>Similaire à "fork" mais sans le "% IDX_MOD".</td>
        </tr>        
        <tr>
            <td>0x10 (aff)</td>
            <td>Il prend un paramètre qui doit être un registre. Il affiche sur la sortie standard le caractère dont le code ASCII est le contenu du registre (en base 10). Un modulo 256 est appliqué à ce code ASCII.</td>
        </tr>
    </tbody>
</table>
</div>

### Le carry :
On vous parle de "carry" depuis un moment mais c'est quoi ? <br>
Tom va vous répondre (faut bien qu'il touche à la doc aussi) :

> Le carry est un boolean qui vaut 1 seulement si l'instruction précédente l'a modifié et qu'elle return 0 sinon il vaut 0 ou il change pas, il est spécifique à un champion.

### Le rôle de la machine :
Le rôle de la machine est simple, elle se doit d'executer le programme donné en paramètre. Elle doit vérifier si, **chaque tour**, les champions ont appelé l'instruction "live" (permettant de signaler que le champion est toujours en vie). <br>
Si après un certains nombres d'execution (représenté par "**NBR_LIVE**") de l'instruction "live" plusieurs processes (champions) sont en vie, alors la machine va commencé un décompte depuis un certain nombre (représenté par "**CYCLE_TO_DIE**" ) en faisant moins un autre nomrbe (représenté par "**CYCLE_DELTA**"). 

> Tout mots mis en gras et en majuscules signifie que la valeur peut-être changer dans le fichier avec le chemin "*include/op.h*".

L'une des particularité qui été obligatoire de notre machine est qu'elle peut-être lancé sans environnement graphique. C'est-à-dire que le programme peut être exécuté et fonctionner efficacement sans nécessiter de système d'interface utilisateur graphique (GUI).
Cela signifie que le programme peut être exécuté en ligne de commande, généralement via un terminal ou une invite de commande, sans avoir besoin d'une interface graphique comme des fenêtres, des boutons, des icônes, etc.


**Beware of -42 Epitech students !!**

