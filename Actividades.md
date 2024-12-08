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
    
    * `lsusb`: Lista los dispositivos conectados a los puertos USB.
    * `lspci`: Muestra los dispositivos conectados al bus PCI.
    * `dmesg | grep usb`: Muestra los mensajes del kernel relacionados con dispositivos USB.
3. Conteste:
    * ¿Qué tipos de dispositivos se muestran en la salida de `lsblk`?
    * ¿Cuál es la diferencia entre `lsusb` y `lspci`?
    * ¿Qué información adicional proporciona `dmesg | grep usb`?
## Actividad 2: Verificar dispositivos de almacenamiento
### Objetivo
Aprender cómo identificar discos duros, particiones y su configuración.

### Instrucciones
1. Use el comando `fdisk -l` para listar todos los discos y particiones.
2. Utilice `blkid` para ver los identificadores UUID y los tipos de sistema de archivos.
3. Use `df -h` para listar los dispositivos montados y su espacio disponible.
4. Conteste:
    * ¿Qué dispositivos de almacenamiento están conectados a su sistema?
    * ¿Qué particiones están montadas actualmente?
    * ¿Qué tipo de sistemas de archivos se usan en las particiones?
## Actividad 3: Explorar dispositivos de entrada
### Objetivo
Identificar dispositivos como teclados, ratones y cámaras.

### Instrucciones
1. Ejecute `cat /proc/bus/input/devices` para listar los dispositivos de entrada.
2. Use `evtest` para monitorear eventos de dispositivos de entrada (requiere permisos de superusuario).
3. Investigue los siguientes dispositivos:
    * Teclado
    * Mouse
    * Controladores USB adicionales
4. Conteste:
    * ¿Qué eventos genera cada dispositivo al interactuar con ellos?
    * ¿Cómo se identifican los dispositivos en `/proc/bus/input/devices`?
## Actividad 4: Examinar dispositivos de salida
### Objetivo
Entender cómo identificar dispositivos de salida como monitores y tarjetas de sonido.

### Instrucciones
1. Use `xrandr` para listar las pantallas conectadas y sus resoluciones.
2. Ejecute `aplay -l` para listar las tarjetas de sonido disponibles.
3. Use `lsof /dev/snd/*` para ver qué procesos están utilizando la tarjeta de sonido.
4. Conteste:
    * ¿Qué salidas de video están disponibles en su sistema?
    * ¿Qué dispositivos de sonido se detectaron?
    * ¿Qué procesos están usando la tarjeta de sonido?
## Actividad 5: Crear un script de resumen
### Objetivo
Automatizar la recopilación de información de dispositivos de entrada y salida.

### Instrucciones
1. Cree un archivo llamado `dispositivos.sh` y agregue el siguiente contenido: ```bash #!/bin/bash echo "Dispositivos de bloque:" lsblk echo "Dispositivos USB:" lsusb echo "Dispositivos PCI:" lspci echo "Dispositivos de entrada:" cat /proc/bus/input/devices echo "Salidas de video:" xrandr echo "Tarjetas de sonido:" aplay -l ```
2. Ejecute el script usando `bash dispositivos.sh`.
3. Modifique el script para guardar la salida en un archivo llamado `resumendispositivos.txt`.
4. Conteste:
    * ¿Qué ventajas tiene usar un script para recopilar esta información?
    * ¿Qué cambios realizaría para personalizar el script?
## Actividad 6: Reflexión y discusión
### Objetivo
Analizar la importancia del manejo de dispositivos en sistemas Linux.

### Instrucciones
1. Reflexione sobre lo aprendido y discuta en equipo:
    * ¿Qué comando encontró más útil y por qué?
    * ¿Qué tan importante es conocer los dispositivos conectados al sistema?
    * ¿Cómo podrían estos conocimientos aplicarse en la administración de sistemas?