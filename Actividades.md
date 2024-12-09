# Actividades: Dispositivos de entrada y salida en Linux
## Introducción
En este ejercicio, aprenderá a listar, verificar y analizar los dispositivos de entrada y salida en Linux. Usarán comandos básicos y herramientas comunes disponibles en cualquier distribución.

## Actividad 1: Listar dispositivos conectados
### Objetivo
Conocer los dispositivos de entrada y salida conectados al sistema.

### Instrucciones
1. Abra una terminal en su entorno Linux.
2. Ejecute los siguientes comandos y anote sus observaciones:
    * `lsblk`: Enumera los dispositivos de bloque.<br>
        1. loop: es un controlador que permite que un archivo pretenda ser un dispositivo de bloque. Dentro del cual hay 15 loops.
        2. sda: el primer disco duro detectado. Dentro del cual se encuentran sda1 (1 MB) y sda2 (25 GB).
        3. sro: La primera unidad de un CD-ROM SCSI.
    * `lsusb`: Lista los dispositivos conectados a los puertos USB.<br>
        1. Linux Foundation 1.1 root hub: falso dispositivo que representa al propio bus.
        2. Linux Foundation 2.0 root hub: falso dispositivo que representa al propio bus.
        3. VirtualBox USB Tablet
    * `lspci`: Muestra los dispositivos conectados al bus PCI.<br>
        1. Muestra varios controladores, de entre los cual la mayoria son de intel, aunque tambien hay de Apple, InnoTek y VMware.
    * `dmesg | grep usb`: Muestra los mensajes del kernel relacionados con dispositivos USB.
        1. Este muestra muchos dispositivos USB, tales como: usbcore, usb usb1, usb usb2, usb usb2-port5, usb 1-1 y usb hid.
3. Conteste:
    * ¿Qué tipos de dispositivos se muestran en la salida de `lsblk`?
        1. loop
        2. sda
        3. sr0
    * ¿Cuál es la diferencia entre `lsusb` y `lspci`?
        1. *lsusb* muestra los dispositivos conectados al bus USB y *lspci* muestra los dispositivos conectados al bus PCI.
    * ¿Qué información adicional proporciona `dmesg | grep usb`?<br>
        1. busca específicamente mensajes relacionados con dispositivos USB en el buffer de mensajes del kernel. 

## Actividad 2: Verificar dispositivos de almacenamiento
### Objetivo
Aprender cómo identificar discos duros, particiones y su configuración.

### Instrucciones
1. Use el comando `fdisk -l` para listar todos los discos y particiones.
    * Hay bastantes particiones, siendo muchas de estas los loop.
2. Utilice `blkid` para ver los identificadores UUID y los tipos de sistema de archivos.
    * Mustre información del disco duro sda2.
3. Use `df -h` para listar los dispositivos montados y su espacio disponible.
    * Mustre más información del disco duro sda2.
4. Conteste:
    * ¿Qué dispositivos de almacenamiento están conectados a su sistema?
        * El disco duro que detecta es el sda, que seria el almacenamiento principal
    * ¿Qué particiones están montadas actualmente?
        * sda y loop
    * ¿Qué tipo de sistemas de archivos se usan en las particiones?
        * para sda se usa ext4
## Actividad 3: Explorar dispositivos de entrada
### Objetivo
Identificar dispositivos como teclados, ratones y cámaras.

### Instrucciones
1. Ejecute `cat /proc/bus/input/devices` para listar los dispositivos de entrada.
    * Muestra varios buses y mas información. Estos buses son de los dispositivos que estan funcionando en el dispositivo.
2. Use `evtest` para monitorear eventos de dispositivos de entrada (requiere permisos de superusuario).
3. Investigue los siguientes dispositivos:
    * Teclado
    * Mouse
    * Controladores USB adicionales
4. Conteste:
    * ¿Qué eventos genera cada dispositivo al interactuar con ellos?
        * Mouse: EV_ABS
        * Teclado: EV_MSC y EV_KEY
    * ¿Cómo se identifican los dispositivos en `/proc/bus/input/devices`?<br>
        * se identifican mediante un formato estructurado que incluye información sobre su tipo, propiedades y controladores.
## Actividad 4: Examinar dispositivos de salida
### Objetivo
Entender cómo identificar dispositivos de salida como monitores y tarjetas de sonido.

### Instrucciones
1. Use `xrandr` para listar las pantallas conectadas y sus resoluciones. 
    * Muestra varias resoluciones, además, informacion de mi configuración de video.
2. Ejecute `aplay -l` para listar las tarjetas de sonido disponibles.
    * Información sobre el sonido.
3. Use `lsof /dev/snd/*` para ver qué procesos están utilizando la tarjeta de sonido.
    * Se muestran 3 procesos.
4. Conteste:
    * ¿Qué salidas de video están disponibles en su sistema? 
        * La salida de video es: Virtual-1
    * ¿Qué dispositivos de sonido se detectaron?
        * Intel 82801AA-ICH
    * ¿Qué procesos están usando la tarjeta de sonido?
        * Intel 82801AA-ICH
## Actividad 5: Crear un script de resumen
### Objetivo
Automatizar la recopilación de información de dispositivos de entrada y salida.

### Instrucciones
1. Cree un archivo llamado `dispositivos.sh` y agregue el siguiente contenido: <br>
```
bash #!/bin/bash 
echo "Dispositivos de bloque:" lsblk 
echo "Dispositivos USB:" lsusb 
echo "Dispositivos PCI:" lspci 
echo "Dispositivos de entrada:" cat /proc/bus/input/devices 
echo "Salidas de video:" xrandr 
echo "Tarjetas de sonido:" aplay -l 
```
2. Ejecute el script usando `bash dispositivos.sh`.
3. Modifique el script para guardar la salida en un archivo llamado `resumendispositivos.txt`.
4. Conteste:
    * ¿Qué ventajas tiene usar un script para recopilar esta información?
        * Es no solo más rapido que ejecutar cada comando, si no que puedes compara esta información en el futuro, además, de que puedes automatizar este reporte de información.
    * ¿Qué cambios realizaría para personalizar el script?
        * Probablemente cambiar el modo en que se muestra esta información, además, de borrar información que talvez yo no necesite.
## Actividad 6: Reflexión y discusión
### Objetivo
Analizar la importancia del manejo de dispositivos en sistemas Linux.

### Instrucciones
1. Reflexione sobre lo aprendido y discuta en equipo:
    * ¿Qué comando encontró más útil y por qué?
        * df -h, para poder ver cuanto espacio tengo disponible.
    * ¿Qué tan importante es conocer los dispositivos conectados al sistema?
        * Una razon es la gestion de los recursos del sistema, además, para la solución de problemas que podrian dar estos mismos.
    * ¿Cómo podrían estos conocimientos aplicarse en la administración de sistemas?
        * Como se menciona en el punto anterior, la gestion de los recursos de un sistema, logrando asi que el sistema que se desarrolle o administre sea eficiente en el uso de recursos.