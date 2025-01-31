// Copyright (c) 2016-2021 The Revolt Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REVOLT_THREADINTERRUPT_H
#define REVOLT_THREADINTERRUPT_H

#include <sync.h>

#include <atomic>
#include <chrono>
#include <condition_variable>

/*
    A helper class for interruptible sleeps. Calling operator() will interrupt
    any current sleep, and after that point operator bool() will return true
    until reset.
*/
class CThreadInterrupt
{
public:
    CThreadInterrupt();
    explicit operator bool() const;
    void operator()() EXCLUSIVE_LOCKS_REQUIRED(!mut);
    void reset();
    bool sleep_for(std::chrono::milliseconds rel_time) EXCLUSIVE_LOCKS_REQUIRED(!mut);
    bool sleep_for(std::chrono::seconds rel_time) EXCLUSIVE_LOCKS_REQUIRED(!mut);
    bool sleep_for(std::chrono::minutes rel_time) EXCLUSIVE_LOCKS_REQUIRED(!mut);

private:
    std::condition_variable cond;
    Mutex mut;
    std::atomic<bool> flag;
};

#endif // REVOLT_THREADINTERRUPT_H
