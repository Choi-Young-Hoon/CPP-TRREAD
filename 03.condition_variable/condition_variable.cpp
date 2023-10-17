#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main(void) {
    std::mutex mutex;
    std::condition_variable condition;

    std::thread thread1([&](){
        {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock);
        }
        std::cout << "thread 1" << std::endl;

    });
    std::thread thread2([&](){
        {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock);
            /*
            condition.wait(lock, [&]() -> bool { 
                return true; // 반환 조건이 참이면 wait을 넘어가 수행한다.
            });
            */
        }
        std::cout << "thread 2" << std::endl;

    });

    // 음... 대기없이 norify를 호출하면 잘 적용이 안된다 스레드가 생성되고 초기화할 시간이 필요한건가?
    // 대기없이 사용하려면 condition_variable의 wait()에서 Predicate를 지정해줘야 할것같다.
    std::this_thread::sleep_for(std::chrono::seconds(1));
    condition.notify_all();
    
    thread1.join();
    thread2.join();
    return 0;
}