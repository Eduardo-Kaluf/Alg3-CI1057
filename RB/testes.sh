#!/bin/sh

clear

make

./myrb < ./testes/moodle_tests/teste1 > ./testes/moodle_tests/teste1.out
diff ./testes/moodle_tests/teste1.sol ./testes/moodle_tests/teste1.out
./myrb < ./testes/moodle_tests/teste2 > ./testes/moodle_tests/teste2.out
diff ./testes/moodle_tests/teste2.sol ./testes/moodle_tests/teste2.out
./myrb < ./testes/moodle_tests/teste3 > ./testes/moodle_tests/teste3.out
diff ./testes/moodle_tests/teste3.sol ./testes/moodle_tests/teste3.out
./myrb < ./testes/moodle_tests/teste4 > ./testes/moodle_tests/teste4.out
diff ./testes/moodle_tests/teste4.sol ./testes/moodle_tests/teste4.out

rm ./testes/moodle_tests/teste1.out
rm ./testes/moodle_tests/teste2.out
rm ./testes/moodle_tests/teste3.out
rm ./testes/moodle_tests/teste4.out

./myrb < ./testes/personal_tests/teste1 > ./testes/personal_tests/teste1.out
diff ./testes/personal_tests/teste1.sol ./testes/personal_tests/teste1.out
./myrb < ./testes/personal_tests/teste2 > ./testes/personal_tests/teste2.out
diff ./testes/personal_tests/teste2.sol ./testes/personal_tests/teste2.out
./myrb < ./testes/personal_tests/teste3 > ./testes/personal_tests/teste3.out
diff ./testes/personal_tests/teste3.sol ./testes/personal_tests/teste3.out
./myrb < ./testes/personal_tests/teste4 > ./testes/personal_tests/teste4.out
diff ./testes/personal_tests/teste4.sol ./testes/personal_tests/teste4.out
./myrb < ./testes/personal_tests/teste5 > ./testes/personal_tests/teste5.out
diff ./testes/personal_tests/teste5.sol ./testes/personal_tests/teste5.out
./myrb < ./testes/personal_tests/teste6 > ./testes/personal_tests/teste6.out
diff ./testes/personal_tests/teste6.sol ./testes/personal_tests/teste6.out

rm ./testes/personal_tests/teste1.out
rm ./testes/personal_tests/teste2.out
rm ./testes/personal_tests/teste3.out
rm ./testes/personal_tests/teste4.out
rm ./testes/personal_tests/teste5.out
rm ./testes/personal_tests/teste6.out

make clean
