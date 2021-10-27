#!/bin/bash
bison gram.ypp
mv gram.tab.cpp gram.tab.hpp
flex lex.l
g++ lex.yy.c my.cpp
rm gram.tab.hpp
rm lex.yy.c
for ii in $(cat tests/test.list)
do
	echo $ii
	i="tests/"$ii".in"
    ./a.out < $i
    echo "-----------------------------------------------"
    echo ""
    echo ""
done
rm a.out
