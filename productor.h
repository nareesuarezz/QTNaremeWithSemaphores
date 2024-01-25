#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include <QThread>
#include <QSemaphore>
#include <QDebug>

class Producer : public QThread {
public:
    void run() override;


private:
    int numberOfProductsToBeProduced;
    int numberOfconsumers;
};

#endif // PRODUCTOR_H
