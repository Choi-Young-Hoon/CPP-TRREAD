#include <iostream>
#include <thread>

void worker() {
    std::cout << "Thread hello" << std::endl;
}

int main(void) {
    std::thread thread1(worker);

    thread1.join();
    return 0;
}