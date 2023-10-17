#include <iostream>
#include <thread>

void worker() {
    std::cout << "Thread hello" << std::endl;
}

void workerArgument(int a, int b) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

int main(void) {
    std::thread thread1(worker);
    thread1.join();

    std::thread thread2(workerArgument, 1, 2);
    thread2.join();

    return 0;
}