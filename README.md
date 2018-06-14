# Momentos invariantes de Hu

El programa obtiene los primeros tres momentos invariantes de HU. Es decir, para traslación, escalamiento y rotación. El programa también obtiene las características de Euler de las imagenes que se le dan.

Las imágenes fueron previamente convertidas en archivos TXT llenos de 0 y 1, donde estos representan un blanco y negro, respectivamente. Estos archivos se encuentran en la carpeta [Images](https://github.com/ferSoto/invariantes-de-momentos/tree/master/Images)

Para compilar el programa, ejecutar la siguiente línea desde Símbolo de sistema estando en la carpeta raíz del proyecto.

```
g++ -Wall -std=c++11 -o Main.exe Main.cpp src/Moments.cpp src/Images.cpp src/EulersCharacteristics.cpp
```

Para usar los archivos TXT en el programa, redireccionar la entrada del programa de la siguiente manera:

```
Main.exe < /ruta/del/archivo/nombre_del_archivo.txt
```
