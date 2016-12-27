yacc -d b_old.y;
lex b.lex;
c++ y.tab.c lex.yy.c -o b -std=c++11 -w;
./b;