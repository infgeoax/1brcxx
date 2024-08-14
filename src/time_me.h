//
// Created by Xiaofeng Li on 14/8/2024.
//

#ifndef INC_1BRC_TIME_ME_H
#define INC_1BRC_TIME_ME_H

#include <chrono>
#include <functional>
#include <utility>

using std::chrono::steady_clock;
using std::chrono::duration;
using std::function;

class TimeMe {
public:
    explicit TimeMe(function<void(duration<double>)> on_timer_end)
            : _start(steady_clock::now()), _on_timer_end(std::move(on_timer_end)) {}

    ~TimeMe() {
        const auto end{steady_clock::now()};
        const duration<double> elapsed_seconds{end - _start};
        _on_timer_end(elapsed_seconds);
    }

private:
    steady_clock::time_point _start;
    function<void(duration<double>)> _on_timer_end;
};

#endif //INC_1BRC_TIME_ME_H
