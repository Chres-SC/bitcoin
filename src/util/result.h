// Copyright (c) 2022 The Revolt Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#ifndef REVOLT_UTIL_RESULT_H
#define REVOLT_UTIL_RESULT_H

#include <util/translation.h>

#include <variant>

/*
 * 'BResult' is a generic class useful for wrapping a return object
 * (in case of success) or propagating the error cause.
*/
template<class T>
class BResult {
private:
    std::variant<bilingual_str, T> m_variant;

public:
    BResult() : m_variant{Untranslated("")} {}
    BResult(T obj) : m_variant{std::move(obj)} {}
    BResult(bilingual_str error) : m_variant{std::move(error)} {}

    /* Whether the function succeeded or not */
    bool HasRes() const { return std::holds_alternative<T>(m_variant); }

    /* In case of success, the result object */
    const T& GetObj() const {
        assert(HasRes());
        return std::get<T>(m_variant);
    }
    T ReleaseObj()
    {
        assert(HasRes());
        return std::move(std::get<T>(m_variant));
    }

    /* In case of failure, the error cause */
    const bilingual_str& GetError() const {
        assert(!HasRes());
        return std::get<bilingual_str>(m_variant);
    }

    explicit operator bool() const { return HasRes(); }
};

#endif // REVOLT_UTIL_RESULT_H
