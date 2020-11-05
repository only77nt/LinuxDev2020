# 08_TestingCoverage
Запуск проекта:
1. autoreconf -fisv
2. ./configure [--enable-gcov] 
3. make
4. make check - чтобы увидеть, что тесты прошли
5. cd src
6. gcov .libs/buf -t -j -k - чтобы увидеть покрытие (должен быть включен флаг)
7. cd ..; make gitclean
