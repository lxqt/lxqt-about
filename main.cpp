/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2010-2011 Razor team
 * Authors:
 *   Petr Vanek <petr@scribus.info>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#include <QtCore>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <lxqt5/Application>
#include <lxqt5/AboutDialog>
#include <lxqt5/GridLayout>
#else
#include <LxQtApplication>
#include <LxQtAboutDialog>
#include <LxQtGridLayout>
#endif

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    //LxQt::GridLayout *g = new LxQt::GridLayout();
    LxQt::Application app(argc, argv);
    LxQt::AboutDialog dlg;
    return app.exec();
}
