/*
 * Multi-producer, single-consumer FIFO queue.
 */

#pragma once

#include "mpsc.hpp"

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

namespace mpsc
{
    template <typename T>
    class Channel
    {
        std::queue<T> items;

        std::mutex lock;

        // https://en.cppreference.com/w/cpp/thread/condition_variable
        // std::condition_variable is a synchronization primitive used with a
        // std::mutex to block one or more threads until another thread both
        // modifies a shared variable (the condition) and notifies the
        // std::condition_variable.
        std::condition_variable waker;

    public:
        Channel() = default;

        void send(T item)
        {
            {
                std::scoped_lock l(lock);
                items.push(std::move(item));
            }
            waker.notify_one();
        }

        T receive()
        {
            std::unique_lock l(lock);
            waker.wait(l, [this]
            {
                return !items.empty();
            });

            assert(!items.empty());
            T item = items.front();
            items.pop();

            return item;
        }

        std::optional<T> try_receive()
        {
            std::unique_lock l(lock);

            if (items.empty())
                return std::nullopt;

            T item = std::move(items.front());
            items.pop();

            return item;
        }

        std::optional<T> receive_timeout(auto timeout)
        {
            std::unique_lock l(lock);

            bool has_item = waker.wait_for(l, timeout, [this]
            {
                return !items.empty();
            });
            if (!has_item)
                return std::nullopt;

            assert(!items.empty());
            T item = std::move(items.front());
            items.pop();

            return item;
        }
    };

    template <typename T>
    class Sender
    {
        std::shared_ptr<Channel<T>> state;

    public:
        explicit Sender(std::shared_ptr<Channel<T>> state) : state(state)
        {
        }

        void send(T item)
        {
            state->send(std::move(item));
        }
    };

    template <typename T>
    class Receiver
    {
        std::shared_ptr<Channel<T>> state;

    public:
        explicit Receiver(std::shared_ptr<Channel<T>> state) : state(state)
        {
        }

        T receive()
        {
            return state->receive();
        }

        std::optional<T> try_receive()
        {
            return state->try_receive();
        }

        std::optional<T> receive_timeout(auto timeout)
        {
            return state->receive_timeout(timeout);
        }
    };

    /**
     * Creates a channel and returns both ends.
     */
    template <typename T>
    std::pair<Sender<T>, Receiver<T>> channel()
    {
        auto state = std::make_shared<Channel<T>>();
        return {Sender<T>{state}, Receiver<T>{state}};
    }
}
