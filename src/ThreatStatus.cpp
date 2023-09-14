#include "ThreatStatus.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

ThreatStatus::ThreatStatus() : board(boardSize, std::vector<ChessPiece>(boardSize, ChessPiece(' ', ' '))) {

}

bool ThreatStatus::isPawnThreatened(int x, int y, char color) const
{

    if (color == 's') {
        if (isValid(x + 1, y - 1) && board[x + 1][y - 1].getType() == 'p' && board[x + 1][y - 1].getColor() == 'b') {
            return true;
        }
        if (isValid(x + 1, y + 1) && board[x + 1][y + 1].getType() == 'p' && board[x + 1][y + 1].getColor() == 'b') {
            return true;
        }
    } else if (color == 'b') {
        if (isValid(x - 1, y - 1) && board[x - 1][y - 1].getType() == 'p' && board[x - 1][y - 1].getColor() == 's') {
            return true;
        }
        if (isValid(x - 1, y + 1) && board[x - 1][y + 1].getType() == 'p' && board[x - 1][y + 1].getColor() == 's') {
            return true;
        }
    }
    return false;
}

bool ThreatStatus::isKnightThreatened(int x, int y, char color) const {

    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            char pieceType = board[newX][newY].getType();
            char pieceColor = board[newX][newY].getColor();
            if (color == 'b' && pieceType == 'a' && pieceColor == 's') {
                return true; // Siyah at tehditi altında
            } else if (color == 's' && pieceType == 'a' && pieceColor == 'b') {
                return true; // Beyaz at tehditi altında
            }
        }
    }
    return false;
}

bool ThreatStatus::isQueenThreatened(int x, int y, char color) const {
    char pieceColor = board[x][y].getColor();

    // Üst, alt, sağ, sol
    if (isThreatenedInDirection(x, y, -1, 0, pieceColor) ||
        isThreatenedInDirection(x, y, 1, 0, pieceColor) ||
        isThreatenedInDirection(x, y, 0, -1, pieceColor) ||
        isThreatenedInDirection(x, y, 0, 1, pieceColor)) {
        return true;
    }

    // Çaprazlar
    if (isThreatenedInDirection(x, y, -1, -1, pieceColor) ||
        isThreatenedInDirection(x, y, -1, 1, pieceColor) ||
        isThreatenedInDirection(x, y, 1, -1, pieceColor) ||
        isThreatenedInDirection(x, y, 1, 1, pieceColor)) {
        return true;
    }

    return false;
}

bool ThreatStatus::isThreatenedInDirection(int x, int y, int deltaX, int deltaY, char color) const {
    while (true) {
        x += deltaX;
        y += deltaY;

        if (!isValid(x, y)) {
            break; // Tahtanın dışına çıktık
        }

        char pieceColor = board[x][y].getColor();
        char pieceType = board[x][y].getType();
        
        if (pieceType != '-') {
            if (pieceType == 'v' && pieceColor != color) {
                return true; // Rakip vezir tehdidi altındayız
            }
            break; // Farklı bir taşla karşılaştık, tehdit yok
        }
    }

    return false; // Hiç tehdit yok
}
bool ThreatStatus::isValid(int x, int y) const {
    return x >= 0 && x < boardSize && y >= 0 && y < boardSize;
}
void ThreatStatus::loadFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            char pieceStr[3];
            inputFile >> pieceStr;
            board[i][j] = ChessPiece(pieceStr[0], pieceStr[1]);
        }
    }
    
    inputFile.close();
}

bool ThreatStatus::isUnderThreat(int x, int y, char color) const {
    if (isQueenThreatened(x, y, color) || isPawnThreatened(x, y, color) || isKnightThreatened(x, y, color)) {
        return true;
    }
    return false;

}
const ChessPiece& ThreatStatus::getPiece(int x, int y) const {
    if (isValid(x, y)) {
        return board[x][y];
    } else {
        // Geçersiz bir pozisyon döndürülebilir veya hata işlenmelidir.
        // Bu duruma göre kodu güncelleyin.
        // Örnek bir hata işleme kodu:
        throw std::runtime_error("Geçersiz pozisyon!");
    }
}

float ThreatStatus::calculateWhiteScore() const {
    float whiteScore = 0;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            float pieceValue = getPiece(i, j).getValue();
            bool isThreatened = isUnderThreat(i, j, getPiece(i, j).getColor());

            if (getPiece(i, j).getColor() == 'b') {
                if (isThreatened) {
                    whiteScore += pieceValue / 2;
                } else {
                    whiteScore += pieceValue;
                }
            }
        }
    }

    return whiteScore;
}

float ThreatStatus::calculateBlackScore() const {
    float blackScore = 0;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            float pieceValue = getPiece(i, j).getValue();
            bool isThreatened = isUnderThreat(i, j, getPiece(i, j).getColor());

            if (getPiece(i, j).getColor() == 's') {
                if (isThreatened) {
                    blackScore += pieceValue / 2;
                } else {
                    blackScore += pieceValue;
                }
            }
        }
    }
    return blackScore;
}

void ThreatStatus::printTotatScore() const {
    float blackScore = calculateBlackScore();
    float whiteScore = calculateWhiteScore();
 
    std::cout << "Siyah Puan: " << blackScore << std::endl;
    std::cout << "Beyaz Puan: " << whiteScore << std::endl;
}
