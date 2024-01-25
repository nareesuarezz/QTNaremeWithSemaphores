#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include "Buffer.h"

class Producer : public QThread {
public:
    Producer(Buffer *buffer);
    void run() override;

private:
    Buffer *buffer;
};

#endif // PRODUCER_H
