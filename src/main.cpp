//
// Created by soofg on 07/01/2022.
//
#include <zmq.hpp>

[[nodiscard]] static auto constexpr
test_nothing() {
    return true;
}

namespace zmq {
    enum pollmode {
        poll_in = ZMQ_POLLIN,
        poll_out = ZMQ_POLLOUT,
        poll_err = ZMQ_POLLERR,
        poll_pri = ZMQ_POLLPRI,
    };
}

typedef enum State {
    TERMINATED = 0,
    ACTIVE = 1,
    PAUSED = 2,
} State;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-use-anyofallof"

[[nodiscard]] static constexpr bool
run_tests() {
    using boolFunc = bool (*)();
    const boolFunc tests[]{
        test_nothing,
    };
    for (const auto test: tests) {
        if (!test()) return false;
    }
    return true;
}

#pragma clang diagnostic pop

[[nodiscard]] static auto
main_loop(const zmq::context_t &mut_ctx, State &mut_state, zmq::socket_t &mut_control) {
    zmq::message_t msg;
    using namespace std::chrono_literals;

    std::vector <zmq::pollitem_t> mut_items_in{
        {mut_control, 0, zmq::pollmode::poll_in, 0},
    };
    while (mut_state != State::TERMINATED) {
        const auto result = zmq::poll(mut_items_in, 1ms);
        if (result) {
            // TODO log, cleanup and exit
            mut_state = State::TERMINATED;
            break;
        }
        for (const zmq::pollitem_t &item: mut_items_in) {
            if (mut_control == item.socket) [[unlikely]] {

            }
        }
        mut_state = State::TERMINATED;
    }
    return mut_state;
}

[[nodiscard]] static auto zmqd_main(zmq::context_t &mut_ctx, State &mut_state) {
    zmq::socket_t control(mut_ctx, zmq::socket_type::sub);
    return main_loop(mut_ctx, mut_state, control);
}

int
main(int argc, char **argv) {
    static_assert(run_tests(), "Compile-time tests failed");
    static zmq::context_t g_mut_ctx{};
    static State g_mut_state{State::ACTIVE};
    return zmqd_main(g_mut_ctx, g_mut_state);
}