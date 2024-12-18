# Comandos de Entrada y Salida, Discos y Archivos

## Ejercicio 1: Montar y Desmontar Discos

### Objetivo: Aprender a montar y desmontar un dispositivo externo.
Inserta una memoria USB en el sistema.

Encuentra el dispositivo usando el comando:

    lsblk

o

    fdisk -l

Monta la memoria USB en un directorio, por ejemplo, `/mnt/usb`:

    sudo mount /dev/sdX1 /mnt/usb

Verifica que esté montado correctamente:

    df -h

Copia un archivo desde tu directorio personal al dispositivo USB:

    cp archivo.txt /mnt/usb/

Desmonta la memoria USB:

    sudo umount /mnt/usb

Salidas y comentarios:<br>
<font color="green">ricardo@ricardo-VirtualBox</font>:~$ lsblk
```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0  73,9M  1 loop /snap/core22/1722
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0   274M  1 loop /snap/firefox/5361
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0     4K  1 loop /snap/bare/5
loop5    7:5    0  11,1M  1 loop /snap/firmware-updater/147
loop6    7:6    0  10,7M  1 loop /snap/firmware-updater/127
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  10,7M  1 loop /snap/snap-store/1218
loop9    7:9    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  44,3M  1 loop /snap/snapd/23258
loop12   7:12   0   568K  1 loop /snap/snapd-desktop-integration/253
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sdb      8:16   1   250G  0 disk 
└─sdb1   8:17   1   250G  0 part /media/ricardo/76E8-CACF
sr0     11:0    1  1024M  0 rom  
```
La memoria USB es sdb1 con 250 GB

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ sudo mount /dev/sdb1 /media/usb <br>

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ lsblk

```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0  73,9M  1 loop /snap/core22/1722
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0   274M  1 loop /snap/firefox/5361
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0     4K  1 loop /snap/bare/5
loop5    7:5    0  11,1M  1 loop /snap/firmware-updater/147
loop6    7:6    0  10,7M  1 loop /snap/firmware-updater/127
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  10,7M  1 loop /snap/snap-store/1218
loop9    7:9    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  44,3M  1 loop /snap/snapd/23258
loop12   7:12   0   568K  1 loop /snap/snapd-desktop-integration/253
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sdb      8:16   1   250G  0 disk 
└─sdb1   8:17   1   250G  0 part /media/usb
sr0     11:0    1  1024M  0 rom  
```

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ df -h
```
S.ficheros     Tamaño Usados  Disp Uso% Montado en
tmpfs            392M   1,7M  390M   1% /run
/dev/sda2         25G    13G   12G  52% /
tmpfs            2,0G    33M  1,9G   2% /dev/shm
tmpfs            5,0M   8,0K  5,0M   1% /run/lock
tmpfs            392M   2,5M  390M   1% /run/user/1000
/dev/sdb1        250G   1,9M  250G   1% /media/usb
```

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ sudo cp archivo.txt /media/usb/

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ sudo umount /media/usb

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ lsblk
```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0  73,9M  1 loop /snap/core22/1722
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0   274M  1 loop /snap/firefox/5361
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0     4K  1 loop /snap/bare/5
loop5    7:5    0  11,1M  1 loop /snap/firmware-updater/147
loop6    7:6    0  10,7M  1 loop /snap/firmware-updater/127
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  10,7M  1 loop /snap/snap-store/1218
loop9    7:9    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  44,3M  1 loop /snap/snapd/23258
loop12   7:12   0   568K  1 loop /snap/snapd-desktop-integration/253
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sdb      8:16   1   250G  0 disk 
└─sdb1   8:17   1   250G  0 part 
sr0     11:0    1  1024M  0 rom  
```


## Ejercicio 2: Redirección de Entrada y Salida

### Objetivo: Usar redirección para guardar la salida de comandos en archivos.

Lista los archivos de tu directorio actual y guarda el resultado en un archivo `listado.txt`:

    ls -l > listado.txt

Muestra el contenido del archivo en la terminal:

    cat listado.txt

Añade la fecha actual al final del archivo:

    date >> listado.txt

Muestra todo el contenido del archivo nuevamente:

    cat listado.txt

Salida y comentarios:

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ ls -l > listado.txt

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ cat listado.txt<br>
```
total 48 
drwxr-xr-x 2 ricardo ricardo 4096 dic  8 15:49 Descargas
-rw-rw-r-- 1 ricardo ricardo  992 dic  8 19:24 dispositivos.sh
drwxr-xr-x 2 ricardo ricardo 4096 dic 10 14:49 Documentos
drwxr-xr-x 3 ricardo ricardo 4096 nov 18 20:20 Escritorio
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Imágenes
-rw-rw-r-- 1 ricardo ricardo    0 dic 10 19:59 listado.txt
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Música
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Plantillas
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Público
-rw-rw-r-- 1 ricardo ricardo 4955 dic  8 19:24 resumendispositivos.txt
drwx------ 6 ricardo ricardo 4096 nov  6 15:00 snap
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Vídeos
```
<font color="green">ricardo@ricardo-VirtualBox</font>:~$ date >> listado.txt

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ cat listado.txt
```
total 48
drwxr-xr-x 2 ricardo ricardo 4096 dic  8 15:49 Descargas
-rw-rw-r-- 1 ricardo ricardo  992 dic  8 19:24 dispositivos.sh
drwxr-xr-x 2 ricardo ricardo 4096 dic 10 14:49 Documentos
drwxr-xr-x 3 ricardo ricardo 4096 nov 18 20:20 Escritorio
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Imágenes
-rw-rw-r-- 1 ricardo ricardo    0 dic 10 19:59 listado.txt
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Música
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Plantillas
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Público
-rw-rw-r-- 1 ricardo ricardo 4955 dic  8 19:24 resumendispositivos.txt
drwx------ 6 ricardo ricardo 4096 nov  6 15:00 snap
drwxr-xr-x 2 ricardo ricardo 4096 nov  5 17:58 Vídeos
mar 10 dic 2024 20:03:04 CST
```

## Ejercicio 3: Copiar y Mover Archivos

### Objetivo: Practicar copiar y mover archivos y directorios.

Crea un archivo de texto llamado `archivo1.txt`:

    echo "Este es un archivo de prueba" > archivo1.txt

Copia este archivo a otro directorio, por ejemplo, `/tmp`:

    cp archivo1.txt /tmp/

Renombra el archivo copiado a `archivo2.txt` en `/tmp`:

    mv /tmp/archivo1.txt /tmp/archivo2.txt

Mueve el archivo `archivo2.txt` de vuelta a tu directorio actual:

    mv /tmp/archivo2.txt .

Salidas y comentarios: <br>

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ echo "Este es un archivo de prueba" > archivo1.txt

Al abrir el archivo tiene el texto "Este es un archivo de prueba", por lo tanto, la sentencia funciono.

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ cp archivo1.txt /tmp/

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ mv /tmp/archivo1.txt /tmp/archivo2.txt

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ mv /tmp/archivo2.txt .

Al verificar el directorio actual note que si se movio.

## Ejercicio 4: Comprimir y Descomprimir Archivos

### Objetivo: Aprender a trabajar con compresión de archivos.

Crea un directorio llamado `backup` y copia algunos archivos en él.

Comprime el directorio `backup` en un archivo `.tar.gz`:

    tar -czvf backup.tar.gz backup/

Borra el directorio original y extrae el contenido del archivo comprimido:

    tar -xzvf backup.tar.gz

Salidas y comentarios:

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ mkdir ./backup

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ tar -czvf backup.tar.gz backup/
```
backup/
backup/Prueba2000.txt
backup/Prueba1000.txt
```

Borre la carpeta como indica el ejercicio

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ tar -xzvf backup.tar.gz
```
backup/
backup/Prueba2000.txt
backup/Prueba1000.txt
```

## Ejercicio 5: Permisos y Propiedades de Archivos

### Objetivo: Aprender a modificar permisos y propietarios de archivos.

Crea un archivo llamado `privado.txt`:

    touch privado.txt

Cambia los permisos del archivo para que solo el propietario pueda leer y escribir:

    chmod 600 privado.txt

Cambia el propietario del archivo a otro usuario (si tienes privilegios):

    sudo chown usuario privado.txt

Salida y comentarios:

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ touch privado.txt

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ chmod 600 privado.txt

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ sudo chown ricardo privado.txt<br>
[sudo] contraseña para ricardo: 



## Ejercicio 6: Exploración de Dispositivos

### Objetivo: Identificar discos y particiones en el sistema.

Usa `lsblk` para listar los discos y particiones:

    lsblk

Usa `du -sh` para ver el tamaño del contenido en un directorio de tu elección:

    du -sh /ruta/directorio

Verifica el uso de disco con `df -h`:

    df -h

Salidas y comentarios: 

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ lsblk
```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0  73,9M  1 loop /snap/core22/1722
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0   274M  1 loop /snap/firefox/5361
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop8    7:8    0  10,7M  1 loop /snap/snap-store/1218
loop9    7:9    0  38,8M  1 loop /snap/snapd/21759
loop10   7:10   0   500K  1 loop /snap/snapd-desktop-integration/178
loop11   7:11   0 505,1M  1 loop /snap/gnome-42-2204/176
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   568K  1 loop /snap/snapd-desktop-integration/253
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sr0     11:0    1  1024M  0 rom  
```

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ du -sh ./backup<br>
4,0K	./backup

El directorio creado en el ejercicio anterior pesa 4 KB.

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ df -h
```
S.ficheros     Tamaño Usados  Disp Uso% Montado en
tmpfs            392M   1,6M  391M   1% /run
/dev/sda2         25G    12G   12G  50% /
tmpfs            2,0G    37M  1,9G   2% /dev/shm
tmpfs            5,0M   8,0K  5,0M   1% /run/lock
tmpfs            392M   2,6M  390M   1% /run/user/1000
```

## Ejercicio 7: Crear y Formatear Particiones

### Objetivo: Crear y formatear una nueva partición (Usar disco de práctica o máquina virtual).

Identifica un disco no particionado:

    sudo fdisk -l

Usa `fdisk` para crear una nueva partición:

    sudo fdisk /dev/sdX

Formatea la partición como `ext4`:

    sudo mkfs.ext4 /dev/sdX1

Monta la partición en un directorio y prueba escribiendo archivos en ella:

    sudo mount /dev/sdX1 /mnt/nueva_particion
    echo "Prueba de escritura" > /mnt/nueva_particion/test.txt

Salida y comentarios:

<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ sudo fdisk -l
```
Disco /dev/loop0: 4 KiB, 4096 bytes, 8 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop1: 73,88 MiB, 77463552 bytes, 151296 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop2: 73,87 MiB, 77459456 bytes, 151288 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop3: 269,77 MiB, 282873856 bytes, 552488 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop4: 274,05 MiB, 287358976 bytes, 561248 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop5: 10,72 MiB, 11239424 bytes, 21952 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop6: 11,11 MiB, 11649024 bytes, 22752 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop7: 91,69 MiB, 96141312 bytes, 187776 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/sda: 25 GiB, 26843545600 bytes, 52428800 sectores
Disk model: VBOX HARDDISK   
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes
Tipo de etiqueta de disco: gpt
Identificador del disco: AE140C23-6A24-481D-8BDA-B90725EF3E0A

Dispositivo Comienzo    Final Sectores Tamaño Tipo
/dev/sda1       2048     4095     2048     1M Arranque de BIOS
/dev/sda2       4096 52426751 52422656    25G Sistema de ficheros de Linux


Disco /dev/loop8: 10,67 MiB, 11186176 bytes, 21848 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop9: 38,83 MiB, 40714240 bytes, 79520 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop10: 500 KiB, 512000 bytes, 1000 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop11: 505,09 MiB, 529625088 bytes, 1034424 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop12: 44,3 MiB, 46448640 bytes, 90720 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop13: 568 KiB, 581632 bytes, 1136 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes
```
```
Disco /dev/sdb: 250 GiB, 268435456000 bytes, 524288000 sectores
Disk model: ProductCode     
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes
Tipo de etiqueta de disco: dos
Identificador del disco: 0xfa2cb833

Dispositivo Inicio Comienzo     Final  Sectores Tamaño Id Tipo
/dev/sdb1              2048 104857600 104855553    50G 83 Linux
```



<font color="green">**ricardo@ricardo-VirtualBox**</font>:~$ sudo mkfs.ext4 /dev/sdb1
```
mke2fs 1.47.0 (5-Feb-2023)
Se está creando un sistema de ficheros con 13106944 bloques de 4k y 3276800 nodos-i
UUID del sistema de ficheros: 3b6fa4a0-a5c4-45ed-a488-9cccd09c0e01
Respaldos del superbloque guardados en los bloques: 
	32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
	4096000, 7962624, 11239424

Reservando las tablas de grupo: hecho                            
Escribiendo las tablas de nodos-i: hecho                            
Creando el fichero de transacciones (65536 bloques):hecho
Escribiendo superbloques y la información contable del sistema de archivos: hecho  
```

Por ultimo montamos la USB y hacemos una prueba creando un archivo

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ sudo mount /dev/sdb1 /media/usb <br>

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ lsblk

```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0  73,9M  1 loop /snap/core22/1722
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0   274M  1 loop /snap/firefox/5361
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0     4K  1 loop /snap/bare/5
loop5    7:5    0  11,1M  1 loop /snap/firmware-updater/147
loop6    7:6    0  10,7M  1 loop /snap/firmware-updater/127
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  10,7M  1 loop /snap/snap-store/1218
loop9    7:9    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  44,3M  1 loop /snap/snapd/23258
loop12   7:12   0   568K  1 loop /snap/snapd-desktop-integration/253
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
sda      8:0    0    25G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    25G  0 part /
sdb      8:16   1   250G  0 disk 
└─sdb1   8:17   1   50G   0 part /media/usb
sr0     11:0    1  1024M  0 rom  
```
<font color="green">ricardo@ricardo-VirtualBox</font>:~$ echo "Prueba de escritura" > /media/usb/test.txt

<font color="green">ricardo@ricardo-VirtualBox</font>:~$ cat /media/usb/test.txt <br>
Prueba de escritura
