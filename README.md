# CFStem-2024
<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/cfstem-2024/blob/main/Im%C3%A1genes%20-%20CFSTEM/WhatsApp%20Image%202024-06-07%20at%202.37.07%20PM%20(2).jpeg" alt="CFSTEM 2024">
    </div>
</div>

## Instalación de la Tarjeta ESP32

Para la instalación en Arduino IDE debemos seguir los siguientes pasos:

1. Abrir ARDUINO IDE
2. Debemos ir a la pestaña ***Archivo***->***Preferencias***.
	- En la pestaña ***Ajustes*** buscamos la opción: ***Gestor de URLs Adicionales de Tarjetas:***
	- Pegamos la siguiente URL: `https://dl.espressif.com/dl/package_esp32_index.json`
	- Luego presionamos la opción ***OK*** y automáticamente se cerrará la ventana.
3. Debemos ir a la pestaña ***Herramientas***->***Placa***->***Gestor de tarjetas***.
	- Colocamos en la barra de búsqueda ***ESP32***.
	- Seleccionamos la opción que nos muestre ***ESP32 Dev Module***.
	- Instalamos y luego presionamos la opción de ***Cerrar***.

Con esto tendremos completa la instalación de nuestra tarjeta ESP32 y lista para ser programada.
## Instalación USB Driver ***(Si no reconoce el puerto COM)***

En algunos casos nuestra PC no es capaz de reconocer el dispositivo USB que nosotros conectamos, es por ello que dejaremos un archivo para la instalación del driver con ello nuestra PC deberá ser capaz de reconocer el dispositivo conectado, en caso de que el problema persista asegúrese de que su dispositivo no se este sobre calentando.

[Si deseas conocer más sobre el chip CH430][CH430-PDF]

[CH430-PDF]: https://cdn.sparkfun.com/datasheets/Dev/Arduino/Other/CH340DS1.PDF

[Descarga este driver para Windows][DRIVER_USB]

[DRIVER_USB]: https://cdn.sparkfun.com/assets/learn_tutorials/8/4/4/CH341SER.EXE

1. Descomprimir el archivo ZIP descargado o dar click en el archivo EXE descargado
2. Seleccionar el archivo para instalación de Windows
	- SETUP.exe
3. Seleccionar CH341SER.INF
4. Click en la opción ***Install***
5. Cuando este instalado cerrar la ventana y listo.

Con esto estaría lista la instalación del Driver USB para nuestra tarjeta en el Sistema Operativo Windows.

Puede seguir está guía para la instalación como una segunda opción 

[Sigue la guía para instalar el driver CH340][DRIVER_CH340]

[DRIVER_CH340]: https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all#drivers-if-you-need-them

<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/cfstem-2024/blob/main/Im%C3%A1genes%20-%20CFSTEM/WhatsApp%20Image%202024-06-07%20at%202.37.07%20PM.jpeg" alt="CFSTEM 2024">
    </div>
</div>
## Pinout

### Voltaje de alimentación
Nombre | GPIO 
--- | --- 
VCC | 5VDC a 12VDC
VSS | GND

### Motores de movimiento (M1 & M2) (M3 & M4)
Nombre | Motor |GPIO 
--- | --- | --- 
AIN_1 | motor1 | 18
AIN_2 | motor2 | 5
PWMA  | motorA | 15
BIN_1 | motor1 | 27
BIN_2 | motor2 | 14
PWMB  | motorB | 2
AIN_11 | motor 3 | 32
AIN_22 | motor 3 | 33
PWMA1  | motorA  | 12
BIN_11 | motor 4 | 25
BIN_22 | motor 4 | 26
PWMB1  | motorB  | 13

## Servomotor de recolección 
Nombre | Motor |GPIO 
--- | --- | --- 
AIN_11 | motor 3 | 32


<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/cfstem-2024/blob/main/Im%C3%A1genes%20-%20CFSTEM/WhatsApp%20Image%202024-06-07%20at%202.37.07%20PM.jpeg" alt="CFSTEM 2024">
    </div>
</div>


## Manejo de motores
Es muy importante que puedas comprender el manejo de los motores realizando un control digital binario (HIGH y LOW) y un control con PWM (valores entre 0 - 255).

Para comprender mejor el tema es recomendable que puedas revisar la hoja de datos de Sparkfun que es el fabricante del módulo TB6612FNG.

**Recuerda que la libreria "TB6612FNG" la puedes encontrar en la parte de arriba en la carpeta "Librerias"**.


## Recomendaciones

1. Si tu tarjeta ESP32 esta conectada a la computadora apaga el switch de encendido de la placa de tu robofut para no dañarla. 
2. Cuando pongás en acción tu RoboFut recuerda tener cargadas tu baterias para un mejor funcionamiento.
3. Revisa tus conexiones siempre antes de programar.
<div>
    <div align=center>
 	<strong>¡Te animamos a mejorar las programaciones base! Libera toda tu imaginación y creatividad para lograr el máximo rendimiento de tu RoboFut. ¡Sabemos que puedes hacerlo!</strong>
    </div>
</div>
