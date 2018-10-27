# Receptor estación meterológica

###### Copyright 2009 Marc Alexander <marc.alexander@gmail.com>
###### Copyright 2009 Jonathan Oxer <jon@oxer.com.au> 

___

Este proyecto aparece en el libro "Practical Arduino" por
Jonathan Oxer y Hugh Blemings (Apress, 2009). Más información
sobre el libro y este proyecto está disponible en:                   
                                                                     
www.practicalarduino.com/projects/medium/weather-station-receiver 
 
 ____
 
 <div class=text-justify>

La increíble popularidad de las estaciones meterológica domésticas 
muestran que no solo los granjeros están interesados en el clima.
Muchas personas quieren ser capaces de hacer un seguimiento y
guardar los eventos meterológica en su entorno local en lugar 
de confiar en servicios estatales o nacional de servicio meterológico  
que no puede tener detalles locales adecuados.

Las estaciones meteorológicas domésticas suelen constar de dos partes
principales: los sensores que se sientan afuera y miden temperatura, 
velocidad y dirección del viento, humedad, lluvia y presión barométrica;
La unidad de pantalla que se encuentra adentro, en un lugar conveniente
para que pueda leer remotamente la temperatura mientras se está sentado
alrededor del fuego calentando sus pies y decidir si hace demasiado frío 
para ir a pescar. Generalmente la parte externa, los sensores se conectan 
entre sí con cables con un sensor que también actúa como un Transmisor 
para enviar actualizaciones de forma inalámbrica a la unidad de visualización.

Muchas estaciones meteorológicas transmiten sus datos a aproximadamente 433MHz 
usando una banda reservada para uso sin licencia de baja potencia, lo cual es 
ideal desde una perspectiva hacker porque los módulos receptores de 433MHz 
están comúnmente disponibles por menos de $ 10 y pueden interconectarse
fácilmente con un Arduino, para permitirle interceptar la fuente de datos.
De hecho, no son solo las estaciones meteorológicas las que utilizan este
enfoque: muchos dispositivos inalámbricos de corto alcance funcionan en la 
misma banda de 433 MHz, por lo que las técnicas utilizadas en este proyecto
se pueden aplicar con la misma facilidad para interceptar datos de otros
dispositivos, como los sistemas domésticos de monitoreo de uso de energía.

Lo mejor de todo es que no se requiere ninguna modificación al dispositivo 
original: simplemente transmite sus datos como de costumbre, sin darse cuenta
de que otro dispositivo los está recibiendo e interpretando. Este proyecto 
es un ejercicio para escuchar una fuente de datos inalámbrica desconocida 
y convertir el flujo de datos sin procesar en valores que tengan sentido.

Una vez que puede recibir los datos y procesarlos en su Arduino, hay un
amplia gama de cosas que puede hacer con la información: puede simplemente
mostrarlo a medida que se actualiza, o puede registrar las lecturas y generar
informes de tendencias a lo largo del tiempo, o incluso puede usarlo como
la base para tomar decisiones, como enviar datos de lluvia a un sistema 
de riego para minimizar el uso de agua.

Para este proyecto utilizamos una estación meteorológica de La Crosse, una 
popular aarca que parece estar disponible en muchas partes del mundo, 
pero el mismo enfoque debería funcionar con otras marcas, ¡siempre que pueda 
calcular el formato de datos! De hecho, muchas estaciones meteorológicas 
(incluido el modelo de La Crosse que usamos) vienen con una interfaz serial 
en la unidad de pantalla para enviar datos a una PC, pero al hacer el trabajo 
directamente en un Arduino con un módulo receptor, ni siquiera necesita de una
unidad de visualización. Y desde muchos sensores de estaciones meteorológicas 
están disponibles de forma individual.Se pueden comprar solo los sensores que
desee y ahorrar algo de dinero en comparación con la compra de un sistema 
completo, además de obtener la flexibilidad de administrar los datos a través de
un Arduino.

</div>

NOTE: Este código es todavía preliminar y está lleno de información de depuración.
Se utiliza al interpretar el protocolo de comunicaciones. Por favor no lo juzgues 
por su estado actual.!
