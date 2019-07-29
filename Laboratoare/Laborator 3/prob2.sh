#!/bin/bash

#script shell ce primeste un sir ca parametru iar urmatorii parametrii (oricati) sunt fisiere
#afisati numele fisierelor (dintre parametrii) care contin sirul respectiv (parametrul 1)
#cel putin 2 parametrii
#verificam daca exista fisierele

#folosim instructiunea shift
# - sare peste un parametru din lista de parametrii

#primul param il salvam intr-o variabila, apoi sarim peste el
SIR=$1
shift

# parcurgem lista de parametrii (care au mai ramas)
for FILE in $*
do
	#daca e fisier
	if [ -f $FILE ]
	then
		#verificam daca sirul apare in fisier, cu grep
		# if grep ceva
		#afisam numele fisierului
		if [[ $(grep $SIR "$FILE" -c) -ge 1 ]]
		then
			echo "$FILE"
		fi
	fi
done
