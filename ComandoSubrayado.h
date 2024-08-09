#ifndef COMANDOSUBRAYADO_H
#define COMANDOSUBRAYADO_H

#include <QTextCursor>
#include <QTextCharFormat>

class Subrayado {
public:
    void aplicar(QTextCursor &cursor) {
        QTextCharFormat format = cursor.charFormat();
        format.setFontUnderline(true); // Aplica subrayado
        cursor.mergeCharFormat(format);
    }
};

#endif // COMANDOSUBRAYADO_H
