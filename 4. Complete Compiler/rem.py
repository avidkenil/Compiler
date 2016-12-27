from __future__ import print_function

f=open("file.txt", 'w');
p=0
p2=0
with open('b.lex') as fp:
    for line in fp:
        newLine = line;
        if "struct node *new" in line:
            p=line.index("struct node *new");
            p2=line.index("return");
            
            newLine = line[:p];
            newLine += line[p2:];
        print(newLine, file=f, end=" ");