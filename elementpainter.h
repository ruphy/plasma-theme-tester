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

class QPaintEvent;
class QString;

namespace Plasma{
    class Svg;
    class SvgPanel;
};

class ElementPainter : public QWidget
{
public:
    ElementPainter(QObject *o);
    ~ElementPainter();
    void setType(const QString &t);
    QString type();
    void refresh();

// public Q_SLOTS:
//     void launchSvgSelector();

protected:
    virtual void paintEvent(QPaintEvent *p);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    Plasma::Svg *m_renderer;
    Plasma::SvgPanel *m_panelRenderer;
    QString m_type;
    QString m_svgPath;
    bool m_usePanelSvg;
};


#endif

