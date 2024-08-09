#ifndef COMANDOCURSIVA_H
#define COMANDOCURSIVA_H

#include "ComandoFormato.h"

#include <QTextCursor>
#include <QTextCharFormat>

class Cursiva {
public:
    void aplicar(QTextCursor &cursor) {
        QTextCharFormat format = cursor.charFormat();
        format.setFontItalic(true);
        cursor.mergeCharFormat(format);
    }
};

#endif // COMANDOCURSIVA_H
