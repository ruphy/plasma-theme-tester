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

void ElementPainter::refresh()
{

}

void ElementPainter::paintEvent(QPainter *p)
{
    m_renderer->paint(p);

}

