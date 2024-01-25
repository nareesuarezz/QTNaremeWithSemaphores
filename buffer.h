#ifndef BUFFER_H
#define BUFFER_H

#include <QSemaphore>
#include <QMutex>
#include <QVector>

class Buffer {
public:
    Buffer(int size);
    void add(int value);
    int get();

private:
    QMutex mutex;
    int size;
    int count;
    QVector<int> data;
};

#endif // BUFFER_H
