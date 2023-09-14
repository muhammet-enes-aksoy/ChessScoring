#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <vector>
#include <string>

// ChessPiece sınıfı, satranç taşlarını temsil eder.
class ChessPiece {
public:
    // Yapıcı fonksiyon, taşın türünü ve rengini belirler.
    ChessPiece(char type, char color);

    // Taşın türünü döndüren işlev.
    char getType() const;

    // Taşın rengini döndüren işlev.
    char getColor() const;

    // Taşın değerini döndüren işlev.
    int getValue() const;

private:
    char type;  // Taş türü (p: Piyon, a: At, f: Fil, k: Kale, v: Vezir, s: Şah)
    char color; // Taş rengi (s: Siyah, b: Beyaz)

    // Taş türüne göre değerini hesaplayan özel bir işlev.
    int getValueFromType(char type) const;
};

#endif
