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

#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "animationscene.h"
#include "resizeableitem.h"

class AddItemCommand : public QUndoCommand
{
public:
    AddItemCommand(qreal x, qreal y, AnimationScene::EditMode mode, QString fileName, AnimationScene *scene, QUndoCommand *parent = 0);
    ~AddItemCommand();

    void undo() override;
    void redo() override;

private:
    ResizeableItem *m_item;
    AnimationScene *m_scene;
};


class DeleteItemCommand : public QUndoCommand
{
public:
    DeleteItemCommand(ResizeableItem *item, AnimationScene *scene, QUndoCommand *parent = 0);
    ~DeleteItemCommand();

    void undo() override;
    void redo() override;

private:
    ResizeableItem *m_item;
    AnimationScene *m_scene;
};

#endif // COMMANDS_H
