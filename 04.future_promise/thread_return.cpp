#include <iostream>
#include <thread>
#include <future>

int main(void) {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread thread1([](std::promise<int>& pro){
        pro.set_value(100);
    }, std::ref(promise));
    thread1.join();

    std::cout << "thread return: " << future.get() << std::endl;
    return 0;
}