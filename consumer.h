#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QSemaphore>
#include <QDebug>

class Consumer : public QThread {
public:
    Consumer(int number);
    Consumer();


    void setConsumerNumber(int newConsumerNumber);

    void setNumberOfProductsToBeProduced(int newNumberOfProductsToBeProduced);

    void setNumberOfconsumers(int newNumberOfconsumers);

protected:
    void run() override;

private:
    int consumerNumber; //Numero del consumidor para que se muestre quien esta consumiendo
    int numberOfProductsToBeProduced;
    int numberOfconsumers;

};

#endif // CONSUMER_H
