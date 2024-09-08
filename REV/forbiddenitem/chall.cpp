#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>   
#include <cstdbool>
#include <sstream> 

using namespace std;

const int BLOCK_SIZE = 128;
const int BYTE_COUNT = BLOCK_SIZE / 8;
const int NIBBLE_SIZE = 4;
const int NIBBLE_COUNT = BLOCK_SIZE / NIBBLE_SIZE;
const int ROUND_NUMBER = 10;

bitset<4> roundKeys[ROUND_NUMBER][NIBBLE_COUNT];
bitset<4> buffer[NIBBLE_COUNT];

int mod(int a, int b){
    return (b + (a % b)) % b;
}

void chrstouint4s(string charArray, bitset<4> *uint4Array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < 2; ++j) {
            uint4Array[i * 2 + j] = bitset<4>((charArray[i] >> (8 - (j + 1) * 4)) & 0x0F);
        }
    }
}

void stringXor(bitset<4> *buffer, bitset<4> *k) {
    for (int i = 0; i < NIBBLE_COUNT; i++) {
        buffer[i] ^= k[i];
    }
}

void indexShiftAdd(bitset<4> *buffer, int shiftNum, bool inverse) {
    bitset<4> temp[NIBBLE_COUNT];
    bitset<4> temp2[NIBBLE_COUNT];
    shiftNum = shiftNum % 2 ? shiftNum : shiftNum + 1;
    if(!inverse){
        for (int i = 0; i < NIBBLE_COUNT; i++) {
            if(i % 2 == 0)
                temp[i] = (buffer[i].to_ulong() + buffer[(i + shiftNum) % NIBBLE_COUNT].to_ulong()) % 16;
            else
                temp[i] = buffer[i].to_ulong() ^ buffer[(i + shiftNum) % NIBBLE_COUNT].to_ulong();
        }
        temp[shiftNum] = buffer[shiftNum];
        temp2[0] = temp[0];
        for (int i = 1; i < NIBBLE_COUNT; i++) {
            temp2[i] = temp[i] ^ temp[i - 1];
        }
    } else {
        temp[0] = buffer[0];
        for (int i = 1; i < NIBBLE_COUNT; i++) {
            temp[i] = buffer[i] ^ temp[i - 1];
        }
        temp2[shiftNum] = temp[shiftNum];
        for (int i = 0; i < NIBBLE_COUNT-1; i++) {
            if(i % 2 == 0)
                temp2[mod(shiftNum * (-i), NIBBLE_COUNT)] = (temp[mod(shiftNum * (-i), NIBBLE_COUNT)].to_ulong() - temp2[mod(shiftNum * (-i+1), NIBBLE_COUNT)].to_ulong()) % 16;
            else
                temp2[mod(shiftNum * (-i), NIBBLE_COUNT)] = temp[mod(shiftNum * (-i), NIBBLE_COUNT)].to_ulong() ^ temp2[mod(shiftNum * (-i+1), NIBBLE_COUNT)].to_ulong();
        }
    }
    for (int i = 0; i < NIBBLE_COUNT; i++) {
        buffer[i] = temp2[i];
    }
}

void indexShiftTrans(bitset<4> *buffer, int shiftNum, bool inverse) {
    bitset<4> temp[NIBBLE_COUNT];
    if (!inverse) {
        for (int i = 0; i < NIBBLE_COUNT; i++) {
            temp[i] = buffer[(i + shiftNum) % NIBBLE_COUNT];
        }
    } else {
        for (int i = 0; i < NIBBLE_COUNT; i++) {
            temp[(i + shiftNum) % NIBBLE_COUNT] = buffer[i];
        }
    }
    
    for (int i = 0; i < NIBBLE_COUNT; i++) {
        buffer[i] = temp[i];
    }
}

int calcSum(bitset<4> *nibbles) {
    int sum = 0;
    for (int i = 0; i < NIBBLE_COUNT; i++) {
        sum += nibbles[i].to_ulong();
    }
    return sum % NIBBLE_COUNT;
}

string pkcs7Padding(string plain) {
    int padLen = BYTE_COUNT - (plain.length() % BYTE_COUNT);
    plain.append(padLen, static_cast<char>(padLen));
    return plain;
}

string removePkcs7Padding(string padded) {
    int padLen = static_cast<int>(padded.back());
    return padded.substr(0, padded.length() - padLen);
}

void prepareRoundKeys(string key) {
    if (key.length() < BYTE_COUNT) {
        key.append(BYTE_COUNT - key.length(), 'F');
    }
    chrstouint4s(key, roundKeys[0], BYTE_COUNT);

    for (int i = 0; i < NIBBLE_COUNT; i++) {
        roundKeys[1][i] = roundKeys[0][NIBBLE_COUNT - i - 1];
    }
    for (int i = 2; i < ROUND_NUMBER; i++) {
        for (int j = 0; j < NIBBLE_COUNT; j++) {
            roundKeys[i][j] = roundKeys[i - 1][(j + 1) % BYTE_COUNT] ^ roundKeys[i - 2][(j + 2) % BYTE_COUNT];
        }
    }
}

string decryptBlock(string cipherBlock) {
    chrstouint4s(cipherBlock, buffer, BYTE_COUNT);

    for (int k = ROUND_NUMBER-1; k >= 0; k--) {
        indexShiftTrans(buffer, calcSum(buffer), true);
        indexShiftAdd(buffer, calcSum(roundKeys[k]), true);
        stringXor(buffer, roundKeys[k]);
    }

    string decrypted;
    decrypted.reserve(NIBBLE_COUNT / 2);
    for (int i = 0; i < NIBBLE_COUNT; i+=2) {
        decrypted += static_cast<char>((buffer[i].to_ulong() << 4) | buffer[i + 1].to_ulong());
    }
    return decrypted;
}

string decrypt(string cipher) {
    string key = ".;D,AWo,asdfnpwe";
    prepareRoundKeys(key);

    string decrypted;
    for (size_t i = 0; i < cipher.length(); i += BYTE_COUNT) {
        decrypted += decryptBlock(cipher.substr(i, BYTE_COUNT));
    }
    return removePkcs7Padding(decrypted);
}

const int MAX_TRANSACTIONS = 3;
const int ITEM_COUNT = 5;
const int FORBIDDEN_ITEM_PRICE = 9999;
const int STARTING_GOLD = 100;

int itemPrices[ITEM_COUNT] = {4, 6, 8, 10, FORBIDDEN_ITEM_PRICE}; // Item prices
string items[ITEM_COUNT] = {"Sword", "Shield", "Potion", "Armor", "Forbidden Item"};


// Function to display ASCII art
void displayShopArt() {
    cout << R"(
  **************************
  *      Welcome to the     *
  *       Item Shop!        *
  **************************
          ___
        .'   '.
       /       \
      |  O   O  |
      |    L    |
       \_______/
        |====|
        |====|
        |____|
    )" << endl;
}

// Function to handle buying an item
void buyItem(int &gold, int itemIndex, bool &hasForbiddenItem, vector<int> &ownedItems) {
    if (itemPrices[itemIndex] > gold) {
        cout << "You don't have enough gold to buy " << items[itemIndex] << endl;
    } else {
        gold -= itemPrices[itemIndex];
        cout << "You bought " << items[itemIndex] << " for " << itemPrices[itemIndex] << " gold!" << endl;
        ownedItems.push_back(itemIndex); // Add the item to owned items
        if (itemIndex == 4) {
            hasForbiddenItem = true;
        }
    }
}

// Function to handle selling an item
void sellItem(int &gold, vector<int> &ownedItems) {
    if (ownedItems.empty()) {
        cout << "You don't own any items to sell!" << endl;
        return;
    }

    cout << "Select an item to sell: " << endl;
    for (int i = 0; i < ownedItems.size(); ++i) {
        int itemIndex = ownedItems[i];
        cout << i + 1 << ". " << items[itemIndex] << " - Sell for " << itemPrices[itemIndex] - 2 << " gold" << endl;
    }

    int sellChoice;
    cin >> sellChoice;

    if (sellChoice < 1 || sellChoice > ownedItems.size()) {
        cout << "Invalid choice!" << endl;
    } else {
        int itemIndex = ownedItems[sellChoice - 1];
        int sellPrice = itemPrices[itemIndex] - 2;
        gold += sellPrice;
        cout << "You sold " << items[itemIndex] << " for " << sellPrice << " gold!" << endl;
        ownedItems.erase(ownedItems.begin() + (sellChoice - 1)); // Remove sold item from ownedItems
    }
}

// Function to handle reading and decrypting the flag.bin file
void readAndDecryptFlag() {
    ifstream file("encrypted.bin", ios::binary);
    if (file.is_open()) {
        string encryptedFlag((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        file.close();

        string decryptedFlag = decrypt(encryptedFlag);
        cout << "Congratulations! You've decrypted the flag: " << decryptedFlag << endl;
    } else {
        cout << "flag.bin file not found!" << endl;
    }
}

int main() {
    int gold = STARTING_GOLD;
    int transactions = 0;
    bool hasForbiddenItem = false;
    vector<int> ownedItems;

    displayShopArt();

    while (transactions < MAX_TRANSACTIONS) {
        cout << "\nYou have " << gold << " gold." << endl;
        cout << "Shop Items:" << endl;
        for (int i = 0; i < ITEM_COUNT; ++i) {
            cout << i + 1 << ". " << items[i] << " - " << itemPrices[i] << " gold" << endl;
        }

        cout << "\nOptions: \n1. Buy Item\n2. Sell Item\n3. Quit" << endl;
        int option;
        cin >> option;

        if (option == 1) {
            cout << "Select an item to buy (1-" << ITEM_COUNT << "): ";
            int itemIndex;
            cin >> itemIndex;
            if (itemIndex >= 1 && itemIndex <= ITEM_COUNT) {
                buyItem(gold, itemIndex - 1, hasForbiddenItem, ownedItems);
                transactions++;
            } else {
                cout << "Invalid item selection!" << endl;
            }
        } else if (option == 2) {
            sellItem(gold, ownedItems);
            transactions++;
        } else if (option == 3) {
            cout << "Exiting the shop." << endl;
            break;
        } else {
            cout << "Invalid option!" << endl;
        }

        if (hasForbiddenItem) {
            readAndDecryptFlag();
            break;
        }
    }

    if (!hasForbiddenItem) {
        cout << "You didn't buy the forbidden item. Game over!" << endl;
    }

    return 0;
}
