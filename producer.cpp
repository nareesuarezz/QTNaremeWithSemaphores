#include "Producer.h"

Producer::Producer(Buffer *buffer) : buffer(buffer) {}

void Producer::run() {
    for(int i = 0; i < 100; ++i) {
        buffer->add(i);
    }
}
