/*
 * Copyright (c) LXQt contributors.
 *
 * This file is part of the LXQt project. <http://lxqt.org>
 * It is distributed under the LGPL 2.1 or later license.
 * Please refer to the LICENSE file for a copy of the license, and
 * the AUTHORS file for copyright and authorship information.
 */

#ifndef TECHNICALINFO_H
#define TECHNICALINFO_H

#include <QList>
#include <QPair>
#include <QDateTime>
#include <QVariant>

class TechInfoTable;

class TechnicalInfo
{
public:
    TechnicalInfo();
    ~TechnicalInfo();

    QString html() const;
    QString text() const;

    TechInfoTable *newTable(const QString &title);
    void add(const TechInfoTable &table);

private:
    QList<TechInfoTable*> mItems;
};

#endif // TECHNICALINFO_H
