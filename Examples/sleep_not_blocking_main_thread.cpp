#include <functional>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>


using namespace std::chrono_literals;

template<class _Rep, class _Period>
std::future<void> TimerAsync(std::chrono::duration<_Rep, _Period> duration, std::function<void()> callback)
{
    return std::async(std::launch::async, [duration, callback]()
    {
        std::this_thread::sleep_for(duration);
        callback();
    });
}


int main()
{
    auto future = TimerAsync(5s, [](){ std::cout << "Timer finished!\n"; });

    while(true)
    {
        // Process main thread queue here

        std::cout << "Processing ... \n";
        std::this_thread::sleep_for(1s); // work simulation


        auto status = future.wait_for(1ms);
        if(status == std::future_status::ready)
            break;
    }

    std::cout << "Finished.\n";


}