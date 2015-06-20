/*
 * Copyright (c) LXQt contributors.
 *
 * This file is part of the LXQt project. <http://lxqt.org>
 * It is distributed under the LGPL 2.1 or later license.
 * Please refer to the LICENSE file for a copy of the license, and
 * the AUTHORS file for copyright and authorship information.
 */

#ifndef LXQT_ABOUTDIALOG_P_H
#define LXQT_ABOUTDIALOG_P_H

#include "ui_lxqtaboutdialog.h"
#include <QDialog>

/**
 * @brief prepares the data to show and fills the form, then shows.
 */
class AboutDialogPrivate: public QDialog, public Ui_about
{
    Q_OBJECT

public:
    AboutDialogPrivate();
    QString titleText() const;
    QString aboutText() const;
    QString authorsText() const;
    QString thanksText() const;
    QString translationsText() const;

public slots:
    void copyToCliboardTechInfo();
};

#endif // LXQT_ABOUTDIALOG_P_H
