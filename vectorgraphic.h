/****************************************************************************
** Copyright (C) 2016 Olaf Japp
**
** This file is part of AnimationMaker.
**
**  AnimationMaker is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  AnimationMaker is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef VECTORGRAPHIC_H
#define VECTORGRAPHIC_H

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include "resizeableitem.h"

class AnimationScene;
class QDomElement;
class Vectorgraphic : public ResizeableItem
{
    Q_OBJECT
public:
    Vectorgraphic();
    Vectorgraphic(QString filename, AnimationScene *scene);
    Vectorgraphic(QByteArray arr, AnimationScene *scene);

    void paint( QPainter *paint, const QStyleOptionGraphicsItem *, QWidget *);
    void scaleObjects();
    void setScale(qreal x, qreal y);
    QByteArray getData();
    void setData(QByteArray data);

    void setAttributeValue(QString attributeName, int value);
    void removeAttribute(QString attributeName);
    void changeAttributeName(QString oldName, QString newName);
    QHash<QString, int> attributes() {return m_attributes;}

    enum { Type = UserType + 5 };
    int type() const Q_DECL_OVERRIDE;

private:
    QGraphicsSvgItem *m_svg;
    QSvgRenderer *m_renderer;
    QByteArray m_data;
    QByteArray m_changedData;
    QHash<QString, int> m_attributes;

    QDomElement elementById(QDomElement root, QString id);
    void reload();
};

#endif // VECTORGRAPHIC_H
