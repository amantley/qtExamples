/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "animNode.h"
#include "edge.h"

#include <QMetaEnum>
#include <QTextStream>
#include <qjsondocument.h>

AnimNode::AnimNode():
    mID("") {
}

AnimNode::AnimNode(const QString &id,
                     AnimNode::NodeType nodeType,
                     QJsonObject data, QJsonArray children) :
    mID(id),
    mNodeType(nodeType)
{
    mData = data;
    mChildren = children;
}

QJsonObject AnimNode::getData() const
{
    return mData;
}

void AnimNode::setData(const QJsonObject &data)
{
    mData = data;
}

QJsonArray AnimNode::getChildren() const
{
    return mChildren;
}

void AnimNode::setChildren(const QJsonArray &children)
{
    mChildren = children;
}

QString AnimNode::getID() const
{
    return mID;
}

void AnimNode::setID(const QString &id)
{
    mID = id;
}

AnimNode::NodeType AnimNode::getNodeType() const
{
    return mNodeType;
}

void AnimNode::setNodeType(AnimNode::NodeType nodeType)
{
    mNodeType = nodeType;
}

//! [0]
int AnimNode::read(const QJsonObject &json, QGraphicsScene* scene, GraphWidget* widget, Node* parent, float parentX, float parentY)
{
    mNode = new Node(widget);
    scene->addItem(mNode);
    scene->addItem(new Edge(mNode, parent));
    QPointF ppos(parentX,parentY);
    mNode->setPos(ppos);

    if (json.contains("id") && json["id"].isString()){
        mID = json["id"].toString();
        mNode->setLabel(mID);
    }

    //QGraphicsSimpleTextItem* mLabel2 = new QGraphicsSimpleTextItem("found a string");
    //scene->addItem(mLabel2);
    //mLabel->setText(json["id"].toString());
    //mLabel->acceptTouchEvents();

    //if (json.contains("level") && json["level"].isDouble())
      //  mLevel = json["level"].toInt();

    if (json.contains("type") && json["type"].isString()){
        if (json["type"] == "randomSwitchStateMachine"){
            mNodeType = NodeType::RandomSwitchStateMachine;
        }else if(json["type"] == "clip") {
            mNodeType = NodeType::Clip;
        }
    }

    if (json.contains("data") && json["data"].isObject()){
            mData = json["data"].toObject();
    }

    if (json.contains("children") && json["children"].isArray()){
        mChildren = json["children"].toArray();
    }

    int childCount = 0;
    for (int childIndex = 0; childIndex < mChildren.size(); ++childIndex) {
        QJsonObject childObject = mChildren[childIndex].toObject();
        AnimNode child;
        float childX = parentX - (mChildren.size()/2) * 50.0;
        childCount += child.read(childObject, scene, widget, mNode, childX + childIndex*50, parentY + 50);
        //childCount++;
        //mNpcs.append(npc);
    }
    return ++childCount;
    //mNodeType = NodeType(json["nodeType"].toInt());
}
//! [0]

//! [1]
void AnimNode::write(QJsonObject &json) const
{
    json["id"] = mID;
    if (mNodeType == NodeType::RandomSwitchStateMachine){
        json["type"] = "randomSwitchStateMachine";
    }else if (mNodeType == NodeType::Clip){
        json["type"] = "clip";
    }
    json["data"] = mData;
    json["children"] = mChildren;
    //json["type"] = mNodeType;
}
//! [1]

void AnimNode::print(int indentation) const
{
    const QString indent(indentation * 2, ' ');
    QTextStream(stdout) << indent << "\"id\": " << "\"" <<  mID <<  "\"\n";

    if (mNodeType == NodeType::RandomSwitchStateMachine){
        QTextStream(stdout) << indent << "\"type\": " << "\"randomSwitchStateMachine\"" << "\n";
    }else if (mNodeType == NodeType::Clip){
        QTextStream(stdout) << indent << "\"type\": " << "clip" << "\n";
    }

    const QJsonObject& temp(mData);
    QJsonDocument doc(temp);
    QString strJson(doc.toJson(QJsonDocument::Indented));
    QTextStream(stdout) << indent << "\"data\": \n" << indent << strJson << "\n";
}

