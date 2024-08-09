#ifndef COMANDOCOMANDOFORMATO_H
#define COMANDOCOMANDOFORMATO_H

#include <QTextCursor>

class ComandoFormato {
public:
    virtual ~ComandoFormato() {}
    virtual void aplicar(QTextCursor &cursor) = 0;
};

#endif // COMANDOCOMANDOFORMATO_H
