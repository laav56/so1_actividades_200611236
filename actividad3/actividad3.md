#!/bin/bash

--Cambio a superusuario
sudo su

--Añado los usuarios
adduser usuario1
adduser usuario2
adduser usuario3

--Muestra información de usuario1
id usuario1

--Elimina usuario3 pero permanece su directorio
deluser usuario3

--Agrego 2 grupos
groupadd grupo1
groupadd grupo2

--Asigno a grupos el usuario1 y usuario2
usermod -aG grupo1 usuario1
usermod -aG grupo2 usaurio2

--Muestro a que grupo pertenece cada usuario
groups usuario1
groups usuario2

--Elimino grupo2
groupdel grupo2

--Cambio la sesión al usuario1
su usuario1

--Creo un archivo txt y escribo algo en el
echo "hola mundo" > archivo1.txt

--Puedo consultar su contendido
cat archivo1.txt

--Creo el directorio
mkdir directorio1

--Me cambio al directorio
cd directorio1

--Creo otro archivo txt escribiendo algo en el
echo "hola mundo 2" > archivo2.txt

--Verifico los permisos
ls -l
ls -ld

--Regreso un nivel
cd ..

--Permisos de lectura y escrituria para el propietario, de lectura para el grupo y nada para el resto

chmod 640 archivo1.txt

--Cambio de directorio
cd directorio1

--Agrego permiso de ejecución para el usuario al archivo
chmod u+x archivo2.txt

--Cambio de grupo propietario el archivo
chgrp grupo1 archivo2.txt

--Subo un nivel
cd ..

--Cambio los permisos del directorio1 para que solo el propietario tenga todos los permisos, el grupo solo lectura y lo demás nada

chmod 740 directorio1

--Cambio de usuario
su usuario2

--Intento acceder al archivo1, permiso denegado
cat: archivo1.txt: Permission denied

--Acceso denegado al archivo2
cat: directorio1/archivo2.txt: Permission denied

--Verificación de permisos ls -l
ls - l
-rw-r----- 1 usuario1 usuario1   11 ago  4 21:16 archivo1.txt
-rw-rw-r-- 1 usuario1 usuario1   13 ago  4 21:45 archivo2.txt
drwxr----- 2 usuario1 usuario1 4096 ago  4 21:45 directorio1

--Verificación de Permisos ls -ld
drwxr-x--- 3 usuario1 usuario1 4096 ago  4 21:45 




