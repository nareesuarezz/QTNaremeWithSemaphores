#include "consumer.h"

// Crear un array de la misma dimensión que el buffer original de cada elemento del buffer que regule cuantas veces ha sido
// leído cada producto y que cuando se haya leído las mismas veces que consumidores hay, que se borre del buffer

extern QSemaphore empty;
extern QSemaphore full;
extern QSemaphore mutex;
extern int buffer[];
extern int currentIndex;
extern int productReadCount[];

Consumer::Consumer(int number) : consumerNumber(number) {}

Consumer::Consumer()
{

}

void Consumer::run() {
    for (int i = 0; i < numberOfProductsToBeProduced; ++i) {
        full.acquire();   // Esperar elemento disponible
        mutex.acquire();  // Entrar a la región crítica
        int productNumber = buffer[i % 5];  // Obtener el número del producto
        productReadCount[i % 5]++;  // Incrementar el contador de lecturas para este producto
        if (productReadCount[i % 5] == numberOfconsumers) {  // Si todos los consumidores han leído este producto
            empty.release();  // Señalar que hay un espacio vacío
        }
        mutex.release();  // Salir de la región crítica
        qDebug() << "Consumer" << consumerNumber << "received product:" << productNumber;
    }
}

void Consumer::setNumberOfconsumers(int newNumberOfconsumers)
{
    numberOfconsumers = newNumberOfconsumers;
}

void Consumer::setNumberOfProductsToBeProduced(int newNumberOfProductsToBeProduced)
{
    numberOfProductsToBeProduced = newNumberOfProductsToBeProduced;
}

void Consumer::setConsumerNumber(int newConsumerNumber)
{
    consumerNumber = newConsumerNumber;
}
