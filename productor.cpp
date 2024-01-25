#include "productor.h"

extern QSemaphore empty;
extern QSemaphore full;
extern QSemaphore mutex;
extern int buffer[];
extern int currentIndex;
extern int numberOfProductsToBeProduced;
void Producer::run() {
    for (int i = 0; i < numberOfProductsToBeProduced; ++i) {
        empty.acquire();  // Esperar espacio vacío
        mutex.acquire();  // Entrar a la región crítica
        buffer[currentIndex] = i;  // Colocar elemento en el búfer
        qDebug() << "Producer produced:" << i;  // Mostrar mensaje del productor
        currentIndex = (currentIndex + 1) % 5;  // Avanzar índice
        mutex.release();  // Salir de la región crítica
        full.release();   // Señalar que hay un elemento disponible
    }
}
