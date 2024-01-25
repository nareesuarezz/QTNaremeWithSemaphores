#include <QCoreApplication>
#include "productor.h"
#include "consumer.h"

const int C = 60; // Capacidad del búfer

QSemaphore empty(C);    // Semaforo para espacios vacíos en el búfer
QSemaphore full(0);     // Semaforo para elementos en el búfer
QSemaphore mutex(1);    // Semaforo para exclusión mutua al acceder al búfer

int productReadCount[C] = {0};  // Inicializar todos los conteos en 0
int buffer[C];          // Búfer compartido
int currentIndex = 0;   // Índice actual en el búfer
const int numberOfProductsToBeProduced = 2000;
const int numberOfconsumers = 5;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear instancias de productor y consumidores
    Producer producer;

    Consumer consumers[numberOfconsumers];

    // Iniciar productor y consumidores
    producer.start();
    for (int i = 0; i < numberOfconsumers; ++i) {
        consumers[i].setConsumerNumber(i);
        consumers[i].start();
    }

    // Esperar a que terminen los consumidores
    for (int i = 0; i < 3; ++i) {
        consumers[i].wait();
    }


    // Esperar a que termine el productor
    producer.wait();

    return a.exec();
}
