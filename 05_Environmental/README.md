# 05_Environmental

## Сборка при помощи autotools:
1) autoscan
2) autoreconf -fisv
3) ./configure <--without-utf>
4) make
5) ./Task

## Замечания:
(*) Если нужно удалить все генераты, то можно выполнить make gitclean или make cleanall
(*) Проблемы с pcre2.h не возникло, всё хорошо собирается и работает

