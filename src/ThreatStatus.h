#ifndef THREATSTATUS_H
#define THREATSTATUS_H

#include "ChessPiece.h"
#include <vector>
#include <string>

// ThreatStatus sınıfı, satranç tahtasının tehdit durumunu hesaplayan bir sınıftır.
class ThreatStatus {
public:
    ThreatStatus(); // Varsayılan yapıcı işlev

    // Belirli bir konumun tehdit altında olup olmadığını kontrol eden işlev.
    bool isUnderThreat(int x, int y, char color) const;

    // Belirli bir konumun geçerli olup olmadığını kontrol eden işlev.
    bool isValid(int x, int y) const;

    // Tahta verilerini dosyadan yükleyen işlev.
    void loadFromFile(const std::string &fileName);

    // Belirli bir konumda bulunan taşı döndüren işlev.
    const ChessPiece &getPiece(int x, int y) const;

    // Tahtanın toplam skorunu ekrana yazdıran işlev.
    void printTotatScore() const;

private:
    static const int boardSize = 8; // Tahta boyutu (8x8)
    std::vector<std::vector<ChessPiece>> board; // Satranç tahtası verisi

    // Belirli bir konumda bir vezirin tehdit altında olup olmadığını kontrol eden işlev.
    bool isQueenThreatened(int x, int y, char color) const;

    // Belirli bir konumda bir taşın belirli bir yönde tehdit altında olup olmadığını kontrol eden işlev.
    bool isThreatenedInDirection(int x, int y, int deltaX, int deltaY, char color) const;

    // Belirli bir konumda bir piyonun tehdit altında olup olmadığını kontrol eden işlev.
    bool isPawnThreatened(int x, int y, char color) const;

    // Belirli bir konumda bir atın tehdit altında olup olmadığını kontrol eden işlev.
    bool isKnightThreatened(int x, int y, char color) const;

    // Beyaz oyuncunun skorunu hesaplayan işlev.
    float calculateWhiteScore() const;

    // Siyah oyuncunun skorunu hesaplayan işlev.
    float calculateBlackScore() const;
};

#endif
