/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#ifndef ELEMENTPAINTER_H
#define ELEMENTPAINTER_H

#include <QWidget>

class QPainter;
class QString;
class Plasma::Svg;

class ElementPainter : public QWidget
{
public:
    ElementPainter();
    void setType(const QString &t);
    QString type();
    void refresh();

protected:
    virtual void paintEvent(QPainter *p);

private:
    Plasma::Svg *m_renderer;
    QString m_type;
};


#endif

