/****************************************************************************
** Meta object code from reading C++ file 'animNode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../elasticnodes/animNode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animNode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnimNode_t {
    QByteArrayData data[5];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimNode_t qt_meta_stringdata_AnimNode = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AnimNode"
QT_MOC_LITERAL(1, 9, 8), // "NodeType"
QT_MOC_LITERAL(2, 18, 24), // "RandomSwitchStateMachine"
QT_MOC_LITERAL(3, 43, 4), // "Clip"
QT_MOC_LITERAL(4, 48, 12) // "StateMachine"

    },
    "AnimNode\0NodeType\0RandomSwitchStateMachine\0"
    "Clip\0StateMachine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimNode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    3,   18,

 // enum data: key, value
       2, uint(AnimNode::RandomSwitchStateMachine),
       3, uint(AnimNode::Clip),
       4, uint(AnimNode::StateMachine),

       0        // eod
};

QT_INIT_METAOBJECT const QMetaObject AnimNode::staticMetaObject = {
    { nullptr, qt_meta_stringdata_AnimNode.data,
      qt_meta_data_AnimNode,  nullptr, nullptr, nullptr}
};

QT_WARNING_POP
QT_END_MOC_NAMESPACE
