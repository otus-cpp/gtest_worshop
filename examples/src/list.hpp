#pragma once

#include <list>
#include <exception>

namespace otus {

    template<typename T, typename Allocator = std::allocator<T>>
    struct List {
        List() = default;
        ~List() = default;

        void push_back(const T& value) {
            m_impl.push_back(value);
        }

        void push_front(const T& value) {
            m_impl.push_front(value);
        }

        void pop_back() {
            if (empty())
                throw std::runtime_error("List is empty!");
            m_impl.pop_back();
        }

        void pop_front() {
            if (empty())
                throw std::runtime_error("List is empty!");
            m_impl.pop_front();
        }

        std::size_t size() const noexcept {
            return m_impl.size();
        }

        bool empty() const noexcept {
            return m_impl.empty();
        }

        T& front() {
            if (empty())
                throw std::runtime_error("List is empty!");
            return m_impl.front();
        }

        const T& front() const {
            if (empty())
                throw std::runtime_error("List is empty!");
            return m_impl.front();
        }

        T& back() {
            if (empty())
                throw std::runtime_error("List is empty!");
            return m_impl.back();
        }

        const T& back() const {
            if (empty())
                throw std::runtime_error("List is empty!");
            return m_impl.back();
        }

    private:
        std::list<T, Allocator> m_impl;
    };

}
