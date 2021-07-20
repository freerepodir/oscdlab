## Disclaimer

These two files correspond to the first task of the 6th program, i.e. "validating" a given expression. This code does not "evaluate" expressions.

## Commands to execute this on PuTTy

yacc -d exec.y <br/>
lex exec.l <br/>
gcc lex.yy.c <br/>
./a.out <br/>
