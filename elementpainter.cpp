/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#include <Plasma/Theme>
#include <Plasma/Svg>

#include <elementpainter.h>

ElementPainter::ElementPainter()
{

}

void ElementPainter::setType(const QString &t)
{
    m_type = t;
}

QString ElementPainter::type()
{
    return m_type;
}

void ElementPainter::refresh()
{

}

void ElementPainter::paintEvent(QPainter *p)
{
    if (m_type == "background") {
        m_renderer->paint(p, QRect(0, 0, width(), height()));
    }
}

