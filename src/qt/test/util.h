// Copyright (c) 2018-2020 The Revolt core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REVOLT_QT_TEST_UTIL_H
#define REVOLT_QT_TEST_UTIL_H

#include <chrono>

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

/**
 * Press "Ok" button in message box dialog.
 *
 * @param text - Optionally store dialog text.
 * @param msec - Number of milliseconds to pause before triggering the callback.
 */
void ConfirmMessage(QString* text, std::chrono::milliseconds msec);

#endif // REVOLT_QT_TEST_UTIL_H
