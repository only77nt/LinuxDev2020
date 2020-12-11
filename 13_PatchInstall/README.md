# 09_I18nL10n
Запуск проекта:
1. autoreconf -fisv
2. ./configure --prefix={some_prefix} (example: /opt/install or /usr)
3. make prefix - сборка и установка в произвольный каталог указанный при помощи префикса
4. make realinstall - сборка по стандартной схеме
5. make gitclean
