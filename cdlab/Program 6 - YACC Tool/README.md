## Disclaimer

validation.y, validation.l => validating the given expression <br/> evaluation.l, evaluation.y => evaluating the given expression

## Commands to execute this on PuTTy

yacc -d filename.y <br/>
lex filename.l <br/>
gcc lex.yy.c y.tab.c ( after this step you may see a warning but ignore it and proceed to the next step ) <br/>
./a.out <br/>
