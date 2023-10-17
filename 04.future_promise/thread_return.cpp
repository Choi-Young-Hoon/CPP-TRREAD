#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main(void) {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread thread1([](std::promise<int>& pro){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        pro.set_value(100);
    }, std::ref(promise));
    
    // future.get()은 promise에서 set_value()가 호출될때까지 대기
    std::cout << "thread return: " << future.get() << std::endl;
    thread1.join();
    return 0;
}