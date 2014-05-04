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


#include <QtCore/QDebug>
#include <QDirIterator>

#include <LxQtApplication>
#include <LxQtAboutDialog>
#include <LxQtGridLayout>



void printHelp()
{
    QTextStream out(stdout);
    out << "Usage: lxqt-about [options]" << endl;
    out << endl;
    out << "Options:" << endl;
    out << "  -h, --help    Show help about options" << endl;
    out << "  --version     Show version information" << endl;
}


void printVersion()
{
    QTextStream out(stdout);
    out << "lxqt-about " << LXQT_VERSION << endl;
}


int main(int argc, char *argv[])
{
    QString configFile;
    for (int i=1; i < argc; ++i)
    {
        QString arg = QString::fromLocal8Bit(argv[i]);

        if (arg == "--help" || arg == "-h")
        {   
            printHelp();
            return 0;
        }

        if (arg == "--version" )
        {   
            printVersion();
            return 0;
        }
 
    }

    //QApplication app(argc, argv);
    //LxQt::GridLayout *g = new LxQt::GridLayout();
    LxQt::Application app(argc, argv);
    LxQt::AboutDialog dlg;
    return app.exec();
}
