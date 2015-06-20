/*
 * Copyright (c) LXQt contributors.
 *
 * This file is part of the LXQt project. <http://lxqt.org>
 * It is distributed under the LGPL 2.1 or later license.
 * Please refer to the LICENSE file for a copy of the license, and
 * the AUTHORS file for copyright and authorship information.
 */

#ifndef TRANSLATORSINFO_H
#define TRANSLATORSINFO_H
#include <QString>
#include <QMap>
#include <QStringList>

#if 0
namespace LxQt
{
#endif

class TranslatorPerson
{
public:
    TranslatorPerson(const QString &englishName, const QString &nativeName, const QString &contact);

    QString englishName() const { return mEnglishName; }
    QString nativeName() const { return mNativeName; }
    QString contact() const { return mContact; }

    QString info() const { return mInfo; }

    void addLanguage(QString langId);
    QString asHtml();

private:
    QString mEnglishName;
    QString mNativeName;
    QString mContact;

    QString mInfo;
    QStringList mLanguages;

};

class TranslatorsInfo
{
public:
    TranslatorsInfo();
    ~TranslatorsInfo();
    QString asHtml() const;

private:
    QMap<QString, TranslatorPerson*> mItems;
    void process(const QString &lang, const QString &englishName, const QString &nativeName, const QString &contact);
};

//} //namecpace LxQt
#endif // TRANSLATORSINFO_H
