#!/bin/sh

clear

make

./myrb < ./testes/teste1 > ./testes/teste1.out
diff ./testes/teste1.sol ./testes/teste1.out
./myrb < ./testes/teste2 > ./testes/teste2.out
diff ./testes/teste2.sol ./testes/teste2.out
./myrb < ./testes/teste3 > ./testes/teste3.out
diff ./testes/teste3.sol ./testes/teste3.out
./myrb < ./testes/teste4 > ./testes/teste4.out
diff ./testes/teste4.sol ./testes/teste4.out

rm ./testes/teste1.out
rm ./testes/teste2.out
rm ./testes/teste3.out
rm ./testes/teste4.out

make clean
