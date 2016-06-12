#include "programme.h"

QStringList Programme::eval() const{
        QString expr=value;
        expr.remove(QChar('['),Qt::CaseInsensitive).remove(QChar(']'),Qt::CaseInsensitive);
        QStringList listeLitterales = expr.split(" ");
        return listeLitterales;
}
