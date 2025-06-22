#!/bin/sh

clear

make

./myht < ./testes/moodle_tests/teste1.in > ./testes/moodle_tests/teste1.out
diff ./testes/moodle_tests/teste1.sol ./testes/moodle_tests/teste1.out
./myht < ./testes/moodle_tests/teste2.in > ./testes/moodle_tests/teste2.out
diff ./testes/moodle_tests/teste2.sol ./testes/moodle_tests/teste2.out
./myht < ./testes/moodle_tests/teste3.in > ./testes/moodle_tests/teste3.out
diff ./testes/moodle_tests/teste3.sol ./testes/moodle_tests/teste3.out
./myht < ./testes/moodle_tests/teste4.in > ./testes/moodle_tests/teste4.out
diff ./testes/moodle_tests/teste4.sol ./testes/moodle_tests/teste4.out

rm ./testes/moodle_tests/teste1.out
rm ./testes/moodle_tests/teste2.out
rm ./testes/moodle_tests/teste3.out
rm ./testes/moodle_tests/teste4.out

make clean
