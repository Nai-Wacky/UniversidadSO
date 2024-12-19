# Actividad Final

## Ricardo Hernández Urbina

### Sistemas de Archivos

#### Ejercicio 1: Concepto y noción de archivo real y virtual
 
**Descripción**:
Define los conceptos de archivo real y archivo virtual y explica sus diferencias.
Identifica ejemplos prácticos de cada tipo en sistemas operativos actuales.
Tareas:
* Define el concepto de archivo real y archivo virtual.<br>
    * Archivo virtual: archivos de uso temporal que se crean durante la ejecucuión de un sistema. Estos son datos generados por el usuario.
    * Archivo real: es aquel que contiene programas, datos o cualquier otro elemento. Estos se almacenan de manera fisica en el disco. 
* Proporciona ejemplos de cómo los sistemas operativos manejan archivos reales y virtuales.
    * Estos archivos se suelen manejar mediante un sistemas de archivos en cual sirve como el intermediario entre el hardware de almacenamiento y el software que necesita los datos, un ejemplo de este manejo aplicado a achivos reales es el siguiente: Cuando guardas un documento en tu computadora, el sistema operativo asigna espacio en el disco, actualiza la tabla de asignación de archivos y escribe los datos en los bloques correspondientes. <br>
    En el caso de los archivos virtuales, seria el siguiente ejemplo: Cuando accedes a /proc/cpuinfo en Linux, el sistema operativo genera dinámicamente el contenido del archivo basado en la información actual del procesador, sin que exista un archivo físico en el disco.
* Explica un caso práctico donde un archivo virtual sea más útil que un archivo real.
    * El uso del /dev/null. Este es un archivo especial en Linux, a menudo referido como el "agujero negro" del sistema de archivos. Es un dispositivo virtual que descarta todos los datos escritos en él y devuelve un carácter de fin de archivo (EOF) cuando se lee. Este comportamiento único lo hace útil para varios propósitos en la programación de shell y la administración de sistemas.

#### Ejercicio 2: Componentes de un sistema de archivos

**Descripción**:
Investiga los componentes principales de un sistema de archivos y compáralos entre dos sistemas operativos, como Linux y Windows.

Tareas:
 * Identifica los componentes clave de un sistema de archivos (por ejemplo, metadatos, tablas de asignación, etc.).
    * Superbloque
    * Inodos
    * Bloques de datos
    * Tabla de asignaciones 
    * Directorios

 * Crea un cuadro comparativo de cómo estos componentes funcionan en sistemas como EXT4 y NTFS.
    * [Tabla comparativa](https://photos.app.goo.gl/qJF987QKQTA7bPXPA)

 * Describe las ventajas y desventajas de cada sistema basado en sus componentes.
    * EXT4 Ventajas:
        * Buen manejo de archivos y volumenes grandes
        * Utiliza arboles B+ para una busqueda rapida
        * Debido a su buen manejo de espacio reduce la fragmentación externa
        * Tiene compatibilidad con anteriores versiones de este sistema de archivos
        * Registo en diario el cual ayuda en proteger la integridad de los datos
    
    * EXT4 Desventajas:
        * No cuenta con cifrado nativo.
        * Sobrecarga de rendimiento debido a los registros diarios
        * Tiene una escalabilidad limitada debido que carece de funciones avanzadas como la asignacion dinamica de inodos
        * Debido al registo en diario se vuelve más dificil la recuperación de archivos que se han corrompido

    * NFTS Ventajas: 
        * Buen manejo de archivos y volumenes grandes
        * Recuperacion de datos en caso de errores
        * Compresión y cifrado de archivos
        * Gestion eficiente de metadatos
    
    * NFTS Desventajas:
        * No se recomienda para volumenes pequeños (Menor a 400 MB).
        * Solo es compatible con sistemas windows, 
        * Tiende a fragmentarse rapidamente
        * Hace uso de muchos recursos lo cual no es ideal en sistemas de recursos limitados.

#### Ejercicio 3: Organización lógica y física de archivos
 
**Descripción**:
Crea un esquema que muestre la organización lógica y física de un sistema de archivos. Explica cómo se relacionan las estructuras lógicas con las físicas en el disco.

Tareas:
 * Diseña un árbol jerárquico que represente la organización lógica de directorios y subdirectorios.
    * / (Raiz del sistema)
        * home/ (Directorio principal de usuarios)
            * user
                * Documentos
                * Descargas
                * Imagenes
                * musica
        * etc/ (Archivos de configuración del sistema)
            * apache2/
            * ssh/
            * systemd/
        * var/ (Datos variables del sistema)
            * log/
                * syslog
                * auth.log
            * www/
                * html/
                * logs/
        * usr/ (Programas y librerías del usuario)
            * bin/
            * lib/
            * share/
                * man/
                * doc/
        * bin/ (Binarios esenciales)
        * lib/ (Librerías esenciales)
        * tmp/ (Archivos temporales)
        * dev/ (Dispositivos del sistema)
            * sda1/
        * boot/ (Archivos de arranque)
        * sys/ (Sistemas virtuales)

* Explica cómo se traduce la dirección lógica a la dirección física en el disco.

    La traducción de una dirección lógica a una dirección física en el disco se realiza mediante la unidad de gestión de memoria (MMU) del sistema operativo.

    Para traducir una dirección lógica en una dirección física en un sistema de paginación:
    1. Descomponga la dirección lógica en número de página y desplazamiento.
    2. Utilice el número de página para encontrar el número de marco correspondiente en la tabla de páginas.
    3. Combine el número de fotograma y el desplazamiento para obtener la dirección física.

* Proporciona un ejemplo práctico de cómo un archivo se almacena físicamente.
    * El usuario crea un archivo llamado "reporte.txt" con 2048 bytes de información.
    * Dado que cada bloque tiene un tamaño de 512 bytes, el archivo necesita 4 bloques. Por lo tanto, se asignarán 4 bloques lógicos consecutivos para almacenar el archivo.
    * El SO asigna asigna las direcciones logicas para cada archivo.
    * El controlador del disco traduce estas direcciones  a posiciones físicas en el discoy se almacenan los datos en el disco duro.
    * SE guarda informacion del archivo en el inodo.

#### Ejercicio 4: Mecanismos de acceso a los archivos
 
**Descripción**:
Simula diferentes mecanismos de acceso a archivos (secuencial, directo e indexado) en un entorno práctico.

Tareas:
 1. Define los diferentes mecanismos de acceso.
    * Secuencial: Los datos se leen o escriben en un orden secuencial, uno tras otro.
    * Directo (Aleatorio): Permite acceder a cualquier parte del archivo directamente, sin necesidad de leer los datos en orden.
    * Indexado: Utiliza una estructura de índice para mantener punteros a bloques de datos específicos, permitiendo un acceso rápido a los registros.
 2. Escribe un pseudocódigo que muestre cómo acceder a:
    1. Un archivo secuencialmente.
    ```
    Abrir archivo "datos.txt" en modo lectura
    Mientras no sea el final de "datos.txt"
        Leer línea
        Imprimir línea
    Cerrar archivo "datos.txt"
    ```
    2. Un archivo directamente mediante su posición.
    ```
    ABRIR archivo EN modo_lectura
    
    DEFINIR posicion_buscada ← 1024  // Posición o bloque específico
    SALTAR_A_POSICION(archivo, posicion_buscada) 
    
    LEER dato_en_posicion DESDE archivo
    IMPRIMIR dato_en_posicion
    
    CERRAR archivo
    ```
    3. Un archivo utilizando un índice.
    ```
    DEFINIR indice ← [100, 512, 1024, 2048]  // Índice con posiciones de los bloques
    
    ABRIR archivo EN modo_lectura
    
    PARA cada posicion EN indice
        SALTAR_A_POSICION(archivo, posicion)
        LEER dato_en_posicion DESDE archivo
        IMPRIMIR "Dato en posición ", posicion, ": ", dato_en_posicion
    FIN PARA
    
    CERRAR archivo
    ```
 3. Compara las ventajas de cada mecanismo dependiendo del caso de uso.
    
    | Caso de uso   | Secuencial    |Directo    |Indexado   |
    | ------------- |:-------------:|:---------:|:---------:|
    | Lectura de archivos de texto    |Eficiente y simple                  |Poco útil                             |Poco útil                       |
    | Procesamiento de logs           |Ideal para análisis cronológico     |Poco útil                             |Poco útil                       |
    | Reproducción multimedia         |Fluido en streaming                 |Ideal para saltos específicos         |Poco común                      |
    | Bases de datos                  |Ineficiente para consultas puntuales|Ideal para accesos directos           |Ideal para búsquedas optimizadas|
    | Sistemas de archivos grandes    |Ineficiente                         |Poco eficiente para recuperación      |Ideal para grandes volúmenes    |
    | Modificaciones de datos binarios|Poco eficiente                      |Ideal para modificar bloques puntuales|Puede ser eficiente con índices |
    
 
#### Ejercicio 5: Modelo jerárquico y mecanismos de recuperación en caso de falla
 
**Descripción**:
Diseña una estructura jerárquica para un sistema de archivos y simula un escenario de falla en el sistema. Describe cómo recuperar los datos utilizando mecanismos de recuperación.

Tareas:
 * Diseña un modelo jerárquico para un sistema de archivos con al menos tres niveles de directorios.

    [Jerarquia](https://photos.app.goo.gl/fLNNf74czFuPn9NGA)

 * Simula una falla en un directorio específico y describe los pasos necesarios para recuperarlo.

    1. Se detecto que el directorio esta corrupto
    1. Comprobar backups del directorio
    1. Restaurar el directorio
    1. Comprobar el estado del directorio

 * Explica qué herramientas o técnicas de respaldo (backup) utilizarías para evitar pérdida de datos.

    Habria 3 tecnicas para hacer el respaldo de los datos
    
    * Respaldo Completo: se hace una copia de todos los datos 
    * Respaldo Incremental: se hace una copia de solo los datos que han cambiado desde el ultimo respaldo 
    * Respaldo en la Nube: se hace una copia de los datos en la nube

### Protección y Seguridad

#### Ejercicio 1: Concepto y objetivos de protección y seguridad
 
**Descripción**:
Investiga los conceptos de protección y seguridad en sistemas operativos. Analiza los objetivos principales que deben cumplir estos mecanismos.

Tareas:
 * Define los conceptos de protección y seguridad en el contexto de sistemas operativos.

    * Protección: se refiere a los mecanismos y políticas implementados por el sistema operativo para controlar el acceso a los recursos del sistema, como archivos, memoria, dispositivos y procesos.
    * Seguridad: se refiere a las medidas y prácticas implementadas para proteger el sistema operativo y sus datos contra amenazas, ataques y vulnerabilidades.

 * Identifica los objetivos principales de un sistema de protección y seguridad, como confidencialidad, integridad y disponibilidad.

    * Confidencialidad: se refiere a la protección de los datos contra el acceso no autorizado. El objetivo es asegurar que solo las personas o sistemas autorizados puedan acceder a la información sensible.
    * Integridad: se refiere a la protección de los datos contra modificaciones no autorizadas o no intencionadas. El objetivo es asegurar que los datos sean precisos y consistentes a lo largo de su ciclo de vida.
    * Disponibilidad: se refiere a la garantía de que los datos y recursos estén accesibles y utilizables cuando se necesiten. El objetivo es minimizar el tiempo de inactividad y asegurar que los usuarios autorizados puedan acceder a los recursos en todo momento.

 * Da un ejemplo práctico de cómo se aplican estos objetivos en un sistema
 operativo. 

    * Confidencialidad: Los permisos de administrador son ejemplo de esto, estos permisos detienen las aplicaciones o al propio de usuario de entrar o modificar carpetas o archivos importantes del sistema
    * Integridad: El sistema operativo puede mantener un control de versiones de los archivos, permitiendo restaurar versiones anteriores en caso de que se detecten cambios no autorizados.
    * Disponibilidad: El sistema operativo realiza respaldos regulares de los datos y la configuración. En caso de fallo del sistema, los datos pueden ser restaurados rápidamente desde los respaldos.

#### Ejercicio 2: Clasificación aplicada a la seguridad

**Descripción**:
Clasifica los mecanismos de seguridad en un sistema operativo y explica cómo cada tipo contribuye a la protección del sistema.

 Tareas:
 * Investiga las clasificaciones comunes de la seguridad, como física, lógica y de red.

    * Física: Se refiere a las medidas y controles implementados para proteger el hardware y las instalaciones físicas donde se encuentran los sistemas informáticos. Dentro de esta hay:
        * Seguridad Contra fuego
        * Segurida Contra agua y polvo
        * Herramientas de vigilancia
        * Control de acceso
        * Seguridad contra picos de corriente
        * Infraestrutura de las instalaciones

    * Lógica: Se centra en proteger los sistemas informáticos, software y datos contra accesos no autorizados, modificaciones y ataques cibernéticos. Dentro de esta hay:
        * Uso de Firewalls a nivel de aplicaciones
        * Cifrado de los datos
        * Control de acceso basado en roles
        * Uso de contraseñas o verificaciones multifactor
        * Uso de softwares para analisis de vulnerabilidades
    
    * Red: Se enfoca en proteger la infraestructura de red y los datos que se transmiten a través de ella. Dentro de esta hay:
        * Uso de Firewalls
        * Redes privadas virtuales (VPN)
        * Control de acceso a la red (NAC)
        * Sistemas de detección y prevención de intrusiones (IDPS)
        * Seguridad del correo electrónico
        * Seguridad de las aplicaciones
        * Seguridad en la nube

 * Explica el papel de cada clasificación en la protección de un sistema operativo.
    * Física: Proteger el hardware y los medios de almacenamiento contra daños físicos, robos y accesos no autorizados.
    * Lógica: Proteger los datos y recursos del sistema operativo contra accesos no autorizados, modificaciones y destrucción.
    * De red:Proteger la comunicación y los datos transmitidos a través de la red contra accesos no autorizados, interceptaciones y ataques.

 * Proporciona ejemplos prácticos de herramientas o técnicas utilizadas en cada clasificación.
    * Seguridad física: 
        * El uso de tarjetas de acceso para restringir el acceso a zonas donde se encuentren los sistemas.
        * Camaras de vigilancia y sistemas de monitoreo
        * Uso de UPS para prevenir que los sistemas se dañem por picos de energia
    * Seguridad lógica: 
        * Control de acceso dependiendo del rol que tenga el usuario
        * Auntenticación multifactor 
        * Cifrar todo dato que pueda ser sensible y de discos
    * Seguridad de red: 
        * Usar firewalls para controlar el trafico de red
        * Usar VPN para una comunicación segura
        * Cifrado de la red como https o tls para garantizar la seguridad de los datos durante la transmisión

#### Ejercicio 3: Funciones del sistema de protección

**Descripción**:
Analiza las funciones que cumple un sistema de protección en un entorno multiusuario.

Tareas:
 * Describe cómo un sistema de protección controla el acceso a los recursos.
    * Se autentica la identidad del usuario o proceso que quiere acceder a los recursos
    * Se verifica que dicho usuario o proceso tenga autorización de poder acceder a los recursos
    * En caso de uso de Control de acceso discresional (DAC) los propietarios deciden si conceder el acceso a los recursos
    * Se registra al usuario o proceso en un registro

 * Explica las funciones principales como autenticación, autorización y auditoría.
    * Auntenticación: Verificar la identidad de los usuarios y procesos antes de permitirles acceder a los recursos del sistema.
    * Autorización: Determinar si un usuario o proceso autenticado tiene permiso para acceder a un recurso específico y realizar ciertas acciones.
    * Auditoría: Mantener un registro de las actividades y accesos a los recursos para detectar y analizar posibles violaciones de seguridad.

 * Diseña un caso práctico donde se muestren las funciones de un sistema de protección en acción.
    * En una empresa tienen un servidor en el cual se almacenan archivos importantes. Se debe garantizar que solo los empleados puedan acceder a la información almacenada y que las activades sean monitoreadas para detectar posibles violaciones de seguridad.
        * Primero se autenticara la identidad usando de quien intente acceder al servidor la autenticacion multifactor (MFA) para asegurarnos de que se trata de un empleado. Ellos tendrán nombre de usuario y contraseña, una vez ingresados se le enviara un codigo de verificación a sus celulares para verificar su identidad.
        * La empresa usa un Control de Acceso Basado en Roles (RBAC) para asignar permisos segun el rol de cada empleado, por lo tanto, dependiendo del rol que estos tengan se le dara ciertos permisos en el servidor
        * Por ultimo, se registrara su ingreso y acciones en el servidor en un registro para su posterior revisión. 

#### Ejercicio 4: Implantación de matrices de acceso

**Descripción**:
Crea e implementa una matriz de acceso para un sistema que contiene usuarios y recursos con diferentes niveles de permisos.

Tareas:
 * Diseña una matriz de acceso para un sistema con al menos 3 usuarios y 4 recursos.
    
    [Matriz](https://photos.app.goo.gl/ArzKnVhYEPZvHDEc6)

 * Explica cómo esta matriz se utiliza para controlar el acceso en un sistema operativo.
    * Esta matriz funcionaria de forma similar al ejemplo del anterior punto; Un proceso entra, se verifica su identidad, y dependiendo de los permisos que se les asigno en la matriz podran realizar ciertas acciones en los recursos en los que tienen dichos permisos y se registran sus actividades.

 * Simula un escenario donde un usuario intenta acceder a un recurso no permitido y cómo la matriz lo bloquea.
    * USER171 entra a un servidor en la empresa donde trabaja, dentro de este servidor hay varios directorios en los cuales se almacenan varios archivos de la empresa, este entra en uno de los directorios en los que tiene solo permisos de lectura e intenta crear un nuevo archivo en este directorio, pero un mensaje de error salta en la pantalla del usuario y le dice que el no tiene permisos para crear archivos en ese directorio para después mostrarle los permisos que tiene el usuario y guardando la acción en el registro.

#### Ejercicio 5: Protección basada en el lenguaje

**Descripción**:
Investiga cómo los lenguajes de programación pueden implementar mecanismos de protección.

Tareas:
 * Explica el concepto de protección basada en el lenguaje.
    * es un enfoque de seguridad en sistemas operativos y entornos de programación que utiliza las características del lenguaje de programación para controlar y restringir el acceso a los recursos. La implementación del lenguaje puede proveer software para hacer cumplir la protección cuando no se pueda validar si el hardware está soportado

 * Proporciona un ejemplo de cómo un lenguaje como Java o Rust asegura la memoria y evita accesos no autorizados.
    * Java: Asegura la memoria a través de la Gestion Automática de la memoria (Garbage Collection), este borra automaticamente los objetos que ya no esten en uso evitando fugas, además, de que Java verifica en tiempo de ejecución que los accesos a arrays estén dentro de los límites válidos. Si se intenta acceder a una posición inválida, lanza una ArrayIndexOutOfBoundsException, evitando la corrupción de memoria. Otra cosa que hace es no permitir el uso de punteros eliminando la posibilidad de manipular directamente direcciones de memoria. 
    
    * Rust: Rust asegura que cada recurso en memoria tenga un único propietario, y cualquier acceso adicional debe hacerse a través de un sistema de préstamos. Cabe agregar que a diferencia de Java, Rust no usa un recolector de basura. En cambio, libera la memoria automáticamente en el momento en que el propietario de un recurso sale de su ámbito. Además, Rust impone reglas estrictas para el acceso concurrente a la memoria. Usa el sistema de préstamos para asegurarse de que los datos sean accesibles por un único hilo de escritura o por múltiples hilos de lectura, pero nunca ambos a la vez. Al igual que Java, Rust realiza verificaciones en tiempo de ejecución para evitar accesos fuera de los límites de arrays o estructuras de datos, lanzando un error en caso de detectar una operación ilegal.

 * Compara este enfoque con otros mecanismos de protección en sistemas operativos.
    | Mecanismo de protección   | Ventajas    |Desventajas    |
    | ------------- |:-------------:|:---------:|
    | Basado en Lenguaje |Integración directa, prevención de errores, encapsulamiento y tipos de datos                  |Dependencia del lenguaje, curva de aprendizaje|
    | ACLs               |Flexibilidad, claridad                                 |Escalabilidad, espacio de almacenamiento|
    | RBAC               |Facilidad de gestión, escalabilidad                    |Rigidez, complejidad inicial            |
    | MAC                |Seguridad estricta, protección contra amenazas internas|Rigidez, complejidad de gestión         |
    

#### Ejercicio 6: Validación y amenazas al sistema

**Descripción**:
Analiza las principales amenazas a un sistema operativo y los mecanismos de validación utilizados para prevenirlas.

Tareas:
 * Investiga y describe al menos tres tipos de amenazas comunes (por
 ejemplo, malware, ataques de fuerza bruta, inyección de código).
    * **RansomWare**: es un malware diseñado para utilizar cifrado para obligar al objetivo del ataque a pagar una demanda de rescate.
    * **Phishing**: técnica que utilizan los ciberdelincuentes para robar información personal y financiera de los usuarios. El objetivo es engañar a las personas para que introduzcan sus datos en sitios web falsos que parecen legítimos, hacer clic en enlaces maliciosos o un archivo.
    * **Ataques de denegacion de servicio (DoS)**: es un ciberataque que impide el acceso de los usuarios legítimos a un recurso o servicio de una red o sistema informático. Esto se logra sobrecargando los recursos computacionales del sistema atacado o consumiendo el ancho de banda de la red de la víctima.

 * Explica los mecanismos de validación como autenticación multifactor y control de integridad.

    * **Autenticación Multifactor (MFA)**: es un proceso en el que se solicita a los usuarios durante el proceso de inicio de sesión una forma adicional de identificación, como un código en su teléfono móvil o un escáner de huellas dactilares.
        * El funcionamiento de la autenticación multifactor se basa en exigir uno o varios de los siguientes métodos de autenticación:
            * Algo que conoce, normalmente una contraseña.
            * Algo que tiene, como un dispositivo de confianza que no se puede duplicar con facilidad (por ejemplo, un teléfono o una clave de hardware).
            * Algo que forma parte de usted, información biométrica como una huella digital o una detección de rostro.
    * **Control de integridad**: Una herramienta de control de integridad es aquella que verifica, contrastando con una base de datos de hechos conocidos, el estado de un sistema para determinar los cambios que en él se han producido. <br>
    Una modificación no controlada de un sistema operativo puede suponer dos cosas: o bien que algún usuario o administrador de éste ha realizado cambios no controlados o documentados, o bien que se ha producido una intrusión en el mismo. Un sistema de verificación de integridad nos permitirá descubrir de forma rápida si alguna parte del sistema se ha visto modificada.
        * Funcionamiento:
            * Generación de copias: Al almacenar datos, el sistema genera una copia del contenido y lo guarda.

            * Verificación de Integridad: Al acceder a los datos, el sistema genera una nueva copia del contenido y lo compara con la copia almacenada.

            * Detección de Cambios: Si las copias no coinciden, el sistema detecta una posible alteración no autorizada y toma medidas para proteger los datos.

 * Diseña un esquema de validación para un sistema operativo con múltiples usuarios. 
    1. **Autenticación**: Se verificara la identidad de los usuarios que inicien sesión en el sistema por medio de autenticación multifactor (MFA) enviando un codigo a su numero de telefono el cual deberan ingresar para poder entrar al sistema.
    2. **Autorización**: Una vez que el usuario inicie sesión se autenticara que permisos tiene el usuario mediante el Control de acceso basado en roles (RBAC). Basados en los permisos concedidos el sistema permitira o denegara el acceso a los recursos solicitados.
    3. **Control de integridad**: Al almacenar datos, el sistema genera un hash del contenido y lo guarda y al acceder a los datos, el sistema genera un nuevo hash del contenido y lo compara con el hash almacenado. Si los hashes no coinciden, el sistema detecta una posible alteración no autorizada y toma medidas para proteger los datos.
    4. **Auditoria**: Por ultimo, se guardan todas las acciones hechas por el usuario en busca de comportamientos sospechosos y alertar a los administradores.

#### Ejercicio 7: Cifrado

**Descripción**:
Explora cómo los mecanismos de cifrado protegen la información en un sistema operativo.

Tareas:
 * Define los conceptos de cifrado simétrico y asimétrico.
    * Simetrico: utiliza la misma clave para cifrar y descifrar los datos. Esto significa que tanto el emisor como el receptor deben conocer y utilizar la misma clave secreta.
    * Asimetrico: utiliza un par de claves; una clave pública para cifrar los datos y una clave privada para descifrarlos. La clave pública puede ser compartida libremente, mientras que la clave privada debe mantenerse en secreto.

 * Proporciona un ejemplo práctico de cada tipo de cifrado aplicado en sistemas operativos.
    
    * **Cifrado simétrico**: se utiliza en herramientas como BitLocker en Windows y LUKS en Linux para proteger discos completos. Este tipo de cifrado es ideal para asegurar datos en reposo, como archivos almacenados en discos duros y unidades de almacenamiento. Utiliza una única clave para cifrar y descifrar la información, lo que significa que cualquier persona que posea la clave puede acceder a los datos cifrados.

    * **Cifrado asimétrico**: se emplea comúnmente en conexiones remotas seguras, como cuando se utiliza SSH en Linux para controlar otra computadora de manera segura. Este método utiliza un par de claves: una clave pública, que puede ser compartida libremente, y una clave privada, que se mantiene en secreto. Esto asegura que, aunque la información viaje por internet, solo el destinatario con la clave privada puede descifrarla y leerla. Este tipo de cifrado es especialmente útil para enviar datos sensibles sin preocupaciones.

 * Simula el proceso de cifrado y descifrado de un archivo con una clave
 dada.
    * Para el cifrado utilice OpenSSL en Linux. El archivo que se cifró es archivo.txt, este archivo se cifró usando como contraseña otro archivo llamado clave.key, y el comando es el siguiente: <br>
    ```
    openssl enc -aes-256-cbc -salt -in archivo.txt -out archivo_cifrado.txt -pass file:./clave.key -pbkdf2
    ```

    [Archivo cifrado](https://photos.app.goo.gl/QnH45JJt2kFRXU28A)

    El comando que utilizariamos para desencriptarlo es el siguiente:

    ```
    openssl enc -d -aes-256-cbc -in archivo_encriptado.txt -out datos_descifrados.txt -pass file:./clave.key -pbkdf2
    ```