/*
 * Copyright (c) LXQt contributors.
 *
 * This file is part of the LXQt project. <http://lxqt.org>
 * It is distributed under the LGPL 2.1 or later license.
 * Please refer to the LICENSE file for a copy of the license, and
 * the AUTHORS file for copyright and authorship information.
 */

#ifndef LXQTRABOUTDIALOG_H
#define LXQTRABOUTDIALOG_H

#include <QDialog>

class AboutDialogPrivate;

/**
 * @brief displays a simple about dialog
 */
class AboutDialog: public QDialog
{
    Q_OBJECT
public:
    AboutDialog();
private:
    AboutDialogPrivate * d_ptr;
};


#endif // LXQTRABOUTDIALOG_H
