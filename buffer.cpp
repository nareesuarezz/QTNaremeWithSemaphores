#include "Buffer.h"
#include <QThread>
Buffer::Buffer(int size) : size(size), count(0), data(size) {}

void Buffer::add(int value) {
    mutex.lock();
    while(count == size) {
        mutex.unlock();
        QThread::yieldCurrentThread();
        mutex.lock();
    }
    data[count] = value;
    ++count;
    mutex.unlock();
}

int Buffer::get() {
    mutex.lock();
    while(count == 0) {
        mutex.unlock();
        QThread::yieldCurrentThread();
        mutex.lock();
    }
    int value = data[0];
    data.remove(0);
    --count;
    mutex.unlock();
    return value;
}
