/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#include <QtGui>

#include <KFileDialog>
#include <kdebug.h>

#include <Plasma/Theme>
#include <Plasma/Svg>
#include <Plasma/SvgPanel>

#include <elementpainter.h>

ElementPainter::ElementPainter(QObject *o)
{
    Q_UNUSED(o);
    m_renderer = 0;
    m_panelRenderer = 0;
    m_svgPath = QString();
}

ElementPainter::~ElementPainter()
{
    delete m_renderer;
    delete m_panelRenderer;
}

void ElementPainter::setType(const QString &t)
{
    m_type = t;

    if (m_type == "background") {
        m_usePanelSvg = true;
    } else {
        m_usePanelSvg = false;
    }

    refresh();
}

QString ElementPainter::type()
{
    return m_type;
}

void ElementPainter::refresh()
{
    //deleting the objects is the only way to get rid of the cache.
    delete m_renderer; m_renderer = 0;
    delete m_panelRenderer; m_panelRenderer = 0;
    
    if (m_usePanelSvg) {
        m_panelRenderer = new Plasma::SvgPanel(m_svgPath);
    } else {
        m_renderer = new Plasma::Svg(m_svgPath);
    }
}

void ElementPainter::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    m_svgPath = KFileDialog::getOpenFileName(KUrl("kfiledialog:///plasma-theme"), "*.svg *.svgz", this);
//     kDebug() << "released";
    refresh();
}

void ElementPainter::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe)
    QPainter p(this);
//     p.begin(this);

    if (m_svgPath.isEmpty()) {
        p.setPen(Qt::black);
        kDebug() << "no file to be loaded. write some info text";
        p.drawText(0, 0, "Click here to load an SVG file for this");
        return;
    }

    if (m_type == "background") {
        m_panelRenderer->paint(&p, QRect(0, 0, width(), height()));
    }

    p.end();
}

