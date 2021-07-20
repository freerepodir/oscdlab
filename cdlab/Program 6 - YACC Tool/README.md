## Disclaimer

exec.y, exec.l => validating the given expression <br/> eval.l, eval.y => evaluating the given expression

## Commands to execute this on PuTTy

yacc -d exec.y <br/>
lex exec.l <br/>
gcc lex.yy.c <br/>
./a.out <br/>
