/****************************************************************************
** Meta object code from reading C++ file 'glWidget.h'
**
** Created: Sun Jul 14 20:54:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../glWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   59,    9,    9, 0x0a,
      86,    9,    9,    9, 0x0a,
      97,    9,    9,    9, 0x0a,
     108,    9,    9,    9, 0x0a,
     123,    9,    9,    9, 0x0a,
     139,  134,    9,    9, 0x0a,
     154,  134,    9,    9, 0x0a,
     169,  134,    9,    9, 0x0a,
     188,  134,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0fps,nVerts,nFaces\0"
    "updateStatusBar(float,int,int)\0fileName\0"
    "openFile(QString)\0fillMode()\0lineMode()\0"
    "fileWireMode()\0fillFlat()\0flag\0"
    "fillMode(bool)\0lineMode(bool)\0"
    "fileWireMode(bool)\0fillFlat(bool)\0"
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLWidget *_t = static_cast<GLWidget *>(_o);
        switch (_id) {
        case 0: _t->updateStatusBar((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fillMode(); break;
        case 3: _t->lineMode(); break;
        case 4: _t->fileWireMode(); break;
        case 5: _t->fillFlat(); break;
        case 6: _t->fillMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->lineMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->fileWireMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->fillFlat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::updateStatusBar(float _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
