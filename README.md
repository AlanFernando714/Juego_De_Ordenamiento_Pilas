🎮 Juego de Ordenamiento con Pilas en C++
📌 Descripción

Este proyecto es un juego de consola desarrollado en C++ que simula un rompecabezas lógico utilizando estructuras de datos tipo pila, implementadas mediante listas enlazadas y memoria dinámica.

El jugador debe ordenar números distribuidos aleatoriamente en distintas pilas, respetando reglas específicas de movimiento.
El proyecto fue desarrollado con fines académicos, como práctica de estructuras de datos.

🎯 Objetivo del juego

Ordenar las pilas de la siguiente manera:

Pila 1: cuatro números 1

Pila 2: cuatro números 2

Pila 3: cuatro números 3

La Pila 4 funciona como pila auxiliar para facilitar los movimientos.

🕹️ Instrucciones de juego

Al iniciar el programa, las pilas 1, 2 y 3 se llenan automáticamente con números aleatorios (1, 2 y 3).

Cada pila puede contener máximo 4 números.

Solo se puede mover el elemento que está en el tope de una pila.

No se permite mover directamente números entre las pilas 1, 2 y 3.

Todos los movimientos deben realizarse a través de la pila 4.

Desde el menú principal puedes:

Elegir una pila (1, 2 o 3).

Mover su tope a la pila 4.

Regresar elementos de la pila 4 a la pila seleccionada.

Selecciona la opción “Comprobar victoria” para verificar si el objetivo ya se cumplió.

🏆 Condición de victoria

El jugador gana cuando:

La pila 1 contiene únicamente cuatro números 1.

La pila 2 contiene únicamente cuatro números 2.

La pila 3 contiene únicamente cuatro números 3.

Al cumplirse estas condiciones, el programa muestra un mensaje de victoria.

⚙️ Conceptos utilizados

Estructuras de datos: Pilas

Listas enlazadas

Uso de punteros

Memoria dinámica (new / delete)

Control de flujo y menús interactivos

Validación de reglas y estados del juego

🛠️ Requisitos

Compilador de C++

Sistema operativo Windows (uso de ibrería windows.h)

Consola o terminal

📚 Tipo de proyecto

Proyecto académico – Estructuras de Datos (C++)

Este proyecto fue desarrollado con fines educativos para reforzar el manejo de pilas, punteros y lógica de programación.

👤 Autor

Alan Fernando Carlos Flores
Estudiante de Ingeniería en Sistemas Computacionales

📄 Licencia

Este proyecto se proporciona con fines educativos.
El autor no se hace responsable del uso indebido del código.