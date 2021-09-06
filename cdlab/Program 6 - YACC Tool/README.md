## Disclaimer

exec.y, exec.l => validating the given expression <br/> eval.l, eval.y => evaluating the given expression

## Commands to execute this on PuTTy

yacc -d exec.y <br/>
lex exec.l <br/>
gcc lex.yy.c y.tab.c ( after this step you may see a warning but ignore it and proceed to the next step ) <br/>
./a.out <br/>
