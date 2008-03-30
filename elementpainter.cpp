/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#include <QtGui>
#include <Plasma/Theme>
#include <Plasma/Svg>
#include <Plasma/SvgPanel>

#include <elementpainter.h>

ElementPainter::ElementPainter()
{

}

void ElementPainter::setType(const QString &t)
{
    m_type = t;

    if (t == "background") {
        if (m_panelRenderer) {
            delete m_panelRenderer;
        }

        delete m_renderer;
        m_renderer = 0;
        m_panelRenderer = new Plasma::SvgPanel;

    } else {
        if (m_renderer) {
            delete m_renderer;
        }

        delete m_panelRenderer;
        m_panelRenderer = 0;
        m_renderer = new Plasma::Svg;
    }
}

QString ElementPainter::type()
{
    return m_type;
}

void ElementPainter::refresh()
{

}

void ElementPainter::paintEvent(QPaintEvent *pe)
{
    QPainter p;
    if (m_type == "background") {
        m_panelRenderer->paint(&p, QRect(0, 0, width(), height()));
    }
   
}

