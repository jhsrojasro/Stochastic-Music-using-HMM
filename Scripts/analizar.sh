#!/bin/bash
cd /home/sebasdeloco/Documentos/Melisma/melisma2003
#for i in 29 30 #$(seq "$2")
#do
#	./noteFiles/debugguer ${i}
#	./meter/meter temp/${i}_debug > temp/${i}_beat
#	rm temp/${i}_debug
#	rm temp/${i}
#	./harmony/harmony temp/${i}_beat | key/key > roman/$1/${i}
#	rm temp/${i}_beat
#done
./clean $1 $2
./dataset/traducir $1