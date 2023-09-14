#include "ChessPiece.h"
#include <string>

// ChessPiece sınıfının yapıcı fonksiyonu
ChessPiece::ChessPiece(char type, char color) : type(type), color(color) {}

// Taşın tipini döndüren işlev
char ChessPiece::getType() const {
    return type;
}

// Taşın rengini döndüren işlev
char ChessPiece::getColor() const {
    return color;
}

// Taş türüne göre değerini hesaplayan işlev
int ChessPiece::getValueFromType(char type) const {
    switch (type) {
        case 'p':
            return 1;
        case 'a':
            return 3;
        case 'f':
            return 3;
        case 'k':
            return 5;
        case 'v':
            return 9;
        case 's':
            return 100;
        default:
            return 0;
    }
}

// Taşın değerini döndüren işlev
int ChessPiece::getValue() const {
    return getValueFromType(type);
}
