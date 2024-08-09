#ifndef COMANDONEGRITA_H
#define COMANDONEGRITA_H

#include <QTextCursor>
#include <QTextCharFormat>

class Negrita {
public:
    void aplicar(QTextCursor &cursor) {
        QTextCharFormat format = cursor.charFormat();
        format.setFontWeight(QFont::Bold);
        cursor.mergeCharFormat(format);
    }
};

#endif // COMANDONEGRITA_H
