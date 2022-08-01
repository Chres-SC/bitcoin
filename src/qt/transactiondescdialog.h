// Copyright (c) 2011-2020 The Revolt core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REVOLT_QT_TRANSACTIONDESCDIALOG_H
#define REVOLT_QT_TRANSACTIONDESCDIALOG_H

#include <QDialog>

namespace Ui {
    class TransactionDescDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class TransactionDescDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDescDialog(const QModelIndex &idx, QWidget *parent = nullptr);
    ~TransactionDescDialog();

private:
    Ui::TransactionDescDialog *ui;
};

#endif // REVOLT_QT_TRANSACTIONDESCDIALOG_H
